#ifndef MANGOS_IO_NETWORKING_WIN32_ASYNCSOCKET_IMPL_H
#define MANGOS_IO_NETWORKING_WIN32_ASYNCSOCKET_IMPL_H

template<typename SocketType>
IO::NetworkError IO::Networking::AsyncSocket<SocketType>::SetNativeSocketOption_NoDelay(bool doNoDelay)
{
    int optionValue = doNoDelay ? 1 : 0;
    int result = ::setsockopt(m_socket._nativeSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&optionValue, sizeof(optionValue));
    if (result != 0)
        return IO::NetworkError(NetworkError::ErrorType::InternalError, ::WSAGetLastError());
    return IO::NetworkError(NetworkError::ErrorType::NoError);
}

template<typename SocketType>
IO::NetworkError IO::Networking::AsyncSocket<SocketType>::SetNativeSocketOption_SystemOutgoingSendBuffer(int bytes)
{
    int optionValue = bytes;
    int result = ::setsockopt(m_socket._nativeSocket, SOL_SOCKET, SO_SNDBUF, (char*)&optionValue, sizeof(optionValue));
    if (result != 0)
        return IO::NetworkError(NetworkError::ErrorType::InternalError, ::WSAGetLastError());
    return IO::NetworkError(NetworkError::ErrorType::NoError);
}

template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::Read(char* target, std::size_t size, std::function<void(IO::NetworkError const&)> const& callback)
{
    int state = m_atomicState.fetch_or(SocketStateFlags::READ_PENDING_SET);
    if (state & SocketStateFlags::READ_PENDING_SET)
    {
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (state & SocketStateFlags::SHUTDOWN_PENDING)
    {
        m_atomicState.fetch_and(~SocketStateFlags::READ_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
        return;
    }

    if (state & SocketStateFlags::READ_PRESENT)
    {
        m_atomicState.fetch_and(~SocketStateFlags::READ_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (size == 0)
    {
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "ERROR: Tried to IO::Networking::AsyncSocket<SocketType>::Read(...) with size 0");
        m_atomicState.fetch_and(~SocketStateFlags::READ_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::NoError)); // technically not an error, we are just done with the buffer
        return;
    }

    m_readCallback = callback;

    int const bufferCount = 1;
    struct BufferCtx
    {
        WSABUF buffers[bufferCount];
    };

    std::shared_ptr<BufferCtx> bufferCtx(new BufferCtx{0});
    bufferCtx->buffers[0].len = size;
    bufferCtx->buffers[0].buf = target;

    m_currentReadTask.InitNew([self = this->shared_from_this(), bufferCtx](DWORD errorCode) {
        uint64_t bytesProcessed = self->m_currentReadTask.InternalHigh;
        if (bytesProcessed == 0)
        { // 0 means the socket is already closed on the other side
            sLog.Out(LOG_NETWORK, LOG_LVL_BASIC, "Empty response -> Going to disconnect.");
            self->CloseSocket();
            auto tmpCallback = std::move(self->m_readCallback);
            self->m_currentReadTask.Reset();
            self->m_atomicState.fetch_and(~SocketStateFlags::READ_PRESENT);
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
            return;
        }

        if (bytesProcessed < bufferCtx->buffers[0].len)
        { // We are not done yet. We need to requeue our task
            bufferCtx->buffers[0].buf += bytesProcessed;
            bufferCtx->buffers[0].len -= bytesProcessed;

            int const bufferCount = 1;
            DWORD flags = 0;
            int errorCode = ::WSARecv(self->m_socket._nativeSocket, bufferCtx->buffers, bufferCount, nullptr, &flags, &(self->m_currentReadTask), nullptr);
            if (errorCode)
            {
                int err = WSAGetLastError();
                if (err != WSA_IO_PENDING) // Pending means that this task was queued (which is what we want)
                {
                    sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[ERROR] ::WSARecv(...) Error: %u", err);
                    auto tmpCallback = std::move(self->m_readCallback);
                    self->m_currentReadTask.Reset();
                    self->m_atomicState.fetch_and(~SocketStateFlags::READ_PRESENT);
                    tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::InternalError, err));
                    return;
                }
            }
        }
        else
        {
            auto tmpCallback = std::move(self->m_readCallback);
            self->m_currentReadTask.Reset();
            self->m_atomicState.fetch_and(~SocketStateFlags::READ_PRESENT);
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::NoError));
        }
    });

    m_atomicState.fetch_or(SocketStateFlags::READ_PRESENT);

    DWORD flags = 0;
    int errorCode = ::WSARecv(m_socket._nativeSocket, bufferCtx->buffers, bufferCount, nullptr, &flags, &m_currentReadTask, nullptr);
    if (errorCode)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) // Pending means that this task was queued (which is what we want)
        {
            sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[ERROR] ::WSARecv(...) Error: %u", err);
            auto tmpCallback = std::move(m_readCallback);
            m_currentReadTask.Reset();
            m_atomicState.fetch_and(~(SocketStateFlags::READ_PENDING_SET | SocketStateFlags::READ_PRESENT));
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::InternalError, err));
            return;
        }
    }
    m_atomicState.fetch_and(~SocketStateFlags::READ_PENDING_SET);
}

/// Warning: Using this function will NOT copy the buffer, dont overwrite it unless callback is triggered!
/// (but a reference to the smart_ptr will be held throughout the transfer, so you dont need to)
template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::Write(std::shared_ptr<std::vector<uint8_t> const> const& source, std::function<void(IO::NetworkError const&)> const& callback)
{
    if (source->size() > 8*1024*1024)
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[NETWORK] You are about to send a very large message (%llu bytes). The Windows Kernel will happily accept that. Split the Write(...) calls next time!", source->size());

    int state = m_atomicState.fetch_or(SocketStateFlags::WRITE_PENDING_SET);
    if (state & SocketStateFlags::WRITE_PENDING_SET)
    {
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (state & SocketStateFlags::SHUTDOWN_PENDING)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
        return;
    }

    if (state & SocketStateFlags::WRITE_PRESENT)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (source->size() == 0)
    {
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "ERROR: Tried to IO::Networking::AsyncSocket<SocketType>::Write(...) with size 0");
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::NoError)); // technically not an error, we are just done with the buffer
        return;
    }

    m_writeCallback = callback;
    m_writeSrcBufferDummyHolder_u8Vector = source;

    int const bufferCount = 1;
    struct BufferCtx
    {
        WSABUF buffers[bufferCount];
    };

    std::shared_ptr<BufferCtx> bufferCtx(new BufferCtx{0});
    bufferCtx->buffers[0].len = source->size();
    bufferCtx->buffers[0].buf = (char*)(source->data());

    m_currentWriteTask.InitNew([self = this->shared_from_this(), bufferCtx](DWORD errorCode) {
        uint64_t bytesProcessed = self->m_currentWriteTask.InternalHigh;

        IO::NetworkError errorResult(IO::NetworkError::ErrorType::InternalError, errorCode);

        if (bytesProcessed == 0)
        { // 0 means the socket is already closed on the other side
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed);
        }
        else if (bytesProcessed < bufferCtx->buffers[0].len || errorCode != 0)
        { // Compared to Read(...), the Write(...) system call should be able to transfer the whole buffer in one
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::InternalError, errorCode);
        }
        else
        {
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::NoError);
        }

        auto tmpCallback = std::move(self->m_writeCallback);
        self->m_writeSrcBufferDummyHolder_u8Vector = nullptr;
        self->m_currentWriteTask.Reset();
        self->m_atomicState.fetch_and(~SocketStateFlags::WRITE_PRESENT);
        tmpCallback(errorResult);
    });

    m_atomicState.fetch_or(SocketStateFlags::WRITE_PRESENT);

    DWORD flags = 0;
    int errorCode = ::WSASend(m_socket._nativeSocket, bufferCtx->buffers, bufferCount, nullptr, flags, &m_currentWriteTask, nullptr);
    if (errorCode)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) // Pending means that this task was queued (which is what we want)
        {
            sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[ERROR] ::WSASend(...) Error: %u", err);
            auto tmpCallback = std::move(m_writeCallback);
            m_writeSrcBufferDummyHolder_u8Vector = nullptr;
            m_currentWriteTask.Reset();
            m_atomicState.fetch_and(~(SocketStateFlags::WRITE_PENDING_SET | SocketStateFlags::WRITE_PRESENT));
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::InternalError, err));
            return;
        }
    }
    m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
}

/// Warning: Using this function will NOT copy the buffer, dont overwrite it unless callback is triggered!
/// (but a reference to the smart_ptr will be held throughout the transfer, so you dont need to)
template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::Write(std::shared_ptr<ByteBuffer const> const& source, std::function<void(IO::NetworkError const&)> const& callback)
{
    if (source->size() > 8*1024*1024)
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[NETWORK] You are about to send a very large message (%llu bytes). The Windows Kernel will happily accept that. Split the Write(...) calls next time!", source->size());

    int state = m_atomicState.fetch_or(SocketStateFlags::WRITE_PENDING_SET);
    if (state & SocketStateFlags::WRITE_PENDING_SET)
    {
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (state & SocketStateFlags::SHUTDOWN_PENDING)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
        return;
    }

    if (state & SocketStateFlags::WRITE_PRESENT)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (source->size() == 0)
    {
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "ERROR: Tried to IO::Networking::AsyncSocket<SocketType>::Write(...) with size 0");
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::NoError)); // technically not an error, we are just done with the buffer
        return;
    }

    m_writeCallback = callback;
    m_writeSrcBufferDummyHolder_ByteBuffer = source;

    int const bufferCount = 1;
    struct BufferCtx
    {
        WSABUF buffers[bufferCount];
    };

    std::shared_ptr<BufferCtx> bufferCtx(new BufferCtx{0});
    bufferCtx->buffers[0].len = source->size();
    bufferCtx->buffers[0].buf = (char*)(source->contents());

    m_currentWriteTask.InitNew([self = this->shared_from_this(), bufferCtx](DWORD errorCode) {
        uint64_t bytesProcessed = self->m_currentWriteTask.InternalHigh;

        IO::NetworkError errorResult(IO::NetworkError::ErrorType::InternalError, errorCode);

        if (bytesProcessed == 0)
        { // 0 means the socket is already closed on the other side
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed);
        }
        else if (bytesProcessed < bufferCtx->buffers[0].len || errorCode != 0)
        { // Compared to Read(...), the Write(...) system call should be able to transfer the whole buffer in one
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::InternalError, errorCode);
        }
        else
        {
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::NoError);
        }

        auto tmpCallback = std::move(self->m_writeCallback);
        self->m_writeSrcBufferDummyHolder_ByteBuffer = nullptr;
        self->m_currentWriteTask.Reset();
        self->m_atomicState.fetch_and(~SocketStateFlags::WRITE_PRESENT);
        tmpCallback(errorResult);
    });

    m_atomicState.fetch_or(SocketStateFlags::WRITE_PRESENT);

    DWORD flags = 0;
    int errorCode = ::WSASend(m_socket._nativeSocket, bufferCtx->buffers, bufferCount, nullptr, flags, &m_currentWriteTask, nullptr);
    if (errorCode)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) // Pending means that this task was queued (which is what we want)
        {
            sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[ERROR] ::WSASend(...) Error: %u", err);
            auto tmpCallback = std::move(m_writeCallback);
            m_writeSrcBufferDummyHolder_ByteBuffer = nullptr;
            m_currentWriteTask.Reset();
            m_atomicState.fetch_and(~(SocketStateFlags::WRITE_PENDING_SET | SocketStateFlags::WRITE_PRESENT));
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::InternalError, err));
            return;
        }
    }
    m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
}

/// Warning: Using this function will NOT copy the buffer, dont overwrite it unless callback is triggered!
/// (but a reference to the smart_ptr will be held throughout the transfer, so you dont need to)
template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::Write(std::shared_ptr<uint8_t const> const& source, uint64_t size, std::function<void(IO::NetworkError const&)> const& callback)
{
    if (size > 8*1024*1024)
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[NETWORK] You are about to send a very large message (%llu bytes). The Windows Kernel will happily accept that. Split the Write(...) calls next time!", size);

    int state = m_atomicState.fetch_or(SocketStateFlags::WRITE_PENDING_SET);
    if (state & SocketStateFlags::WRITE_PENDING_SET)
    {
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (state & SocketStateFlags::SHUTDOWN_PENDING)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
        return;
    }

    if (state & SocketStateFlags::WRITE_PRESENT)
    {
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (size == 0)
    {
        sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "ERROR: Tried to IO::Networking::AsyncSocket<SocketType>::Write(...) with size 0");
        m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::NoError)); // technically not an error, we are just done with the buffer
        return;
    }

    m_writeCallback = callback;
    m_writeSrcBufferDummyHolder_rawArray = source;

    int const bufferCount = 1;
    struct BufferCtx
    {
        WSABUF buffers[bufferCount];
    };

    std::shared_ptr<BufferCtx> bufferCtx(new BufferCtx{0});
    bufferCtx->buffers[0].len = size;
    bufferCtx->buffers[0].buf = (char*)source.get();

    m_currentWriteTask.InitNew([self = this->shared_from_this(), bufferCtx](DWORD errorCode) {
        uint64_t bytesProcessed = self->m_currentWriteTask.InternalHigh;

        IO::NetworkError errorResult(IO::NetworkError::ErrorType::InternalError, errorCode);

        if (bytesProcessed == 0)
        { // 0 means the socket is already closed on the other side
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed);
        }
        else if (bytesProcessed < bufferCtx->buffers[0].len || errorCode != 0)
        { // Compared to Read(...), the Write(...) system call should be able to transfer the whole buffer in one
            self->CloseSocket();
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::InternalError, errorCode);
        }
        else
        {
            errorResult = IO::NetworkError(IO::NetworkError::ErrorType::NoError);
        }

        auto tmpCallback = std::move(self->m_writeCallback);
        self->m_writeSrcBufferDummyHolder_rawArray = nullptr;
        self->m_currentWriteTask.Reset();
        self->m_atomicState.fetch_and(~SocketStateFlags::WRITE_PRESENT);
        tmpCallback(errorResult);
    });

    m_atomicState.fetch_or(SocketStateFlags::WRITE_PRESENT);

    DWORD flags = 0;
    int errorCode = ::WSASend(m_socket._nativeSocket, bufferCtx->buffers, bufferCount, nullptr, flags, &m_currentWriteTask, nullptr);
    if (errorCode)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) // Pending means that this task was queued (which is what we want)
        {
            sLog.Out(LOG_NETWORK, LOG_LVL_ERROR, "[ERROR] ::WSASend(...) Error: %u", err);
            auto tmpCallback = std::move(m_writeCallback);
            m_writeSrcBufferDummyHolder_rawArray = nullptr;
            m_currentWriteTask.Reset();
            m_atomicState.fetch_and(~(SocketStateFlags::WRITE_PENDING_SET | SocketStateFlags::WRITE_PRESENT));
            tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::InternalError, err));
            return;
        }
    }
    m_atomicState.fetch_and(~SocketStateFlags::WRITE_PENDING_SET);
}

template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::CloseSocket()
{
    // set SHUTDOWN_PENDING flag, and check if there was already a previous one
    if (m_atomicState.fetch_or(SocketStateFlags::SHUTDOWN_PENDING) & SocketStateFlags::SHUTDOWN_PENDING)
        return; // there was already a ::close()

    sLog.Out(LOG_NETWORK, LOG_LVL_DEBUG, "CloseSocket(): Disconnect request");
    ::closesocket(m_socket._nativeSocket); // will interrupt and fail all pending IOCP events and post them to the queue
}

/// The callback is invoked in the IO thread
/// Useful for computational expensive operations (e.g. packing and encryption), that should be avoided in the main loop
template<typename SocketType>
void IO::Networking::AsyncSocket<SocketType>::EnterIoContext(std::function<void(IO::NetworkError)> const& callback)
{
    int state = m_atomicState.fetch_or(SocketStateFlags::CONTEXT_PENDING_SET);
    if (state & SocketStateFlags::CONTEXT_PENDING_SET)
    {
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    if (state & SocketStateFlags::SHUTDOWN_PENDING)
    {
        m_atomicState.fetch_and(~SocketStateFlags::CONTEXT_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::SocketClosed));
        return;
    }

    if (state & SocketStateFlags::CONTEXT_PRESENT)
    {
        m_atomicState.fetch_and(~SocketStateFlags::CONTEXT_PENDING_SET);
        callback(IO::NetworkError(IO::NetworkError::ErrorType::OnlyOneTransferPerDirectionAllowed));
        return;
    }

    m_contextCallback = callback;

    m_currentContextTask.InitNew([self = this->shared_from_this()](DWORD errorCode) {
        auto tmpCallback = std::move(self->m_contextCallback);
        self->m_currentContextTask.Reset();
        self->m_atomicState.fetch_and(~SocketStateFlags::CONTEXT_PRESENT);
        tmpCallback(IO::NetworkError(IO::NetworkError::ErrorType::NoError));
    });

    m_atomicState.fetch_xor(SocketStateFlags::CONTEXT_PRESENT | SocketStateFlags::CONTEXT_PENDING_SET); // set PRESENT and unset PENDING_SET

    m_ctx->PostOperationForImmediateInvocation(&m_currentContextTask);
}

#endif //MANGOS_IO_NETWORKING_WIN32_ASYNCSOCKET_IMPL_H
