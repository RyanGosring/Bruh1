#ifndef MANGOS_IO_NETWORKING_WIN32_IOCPOPERATIONEVENT_H
#define MANGOS_IO_NETWORKING_WIN32_IOCPOPERATIONEVENT_H

#include <string>
#include <functional>
#include "../../../../Errors.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef WIN32_LEAN_AND_MEAN

class IocpOperationTask : public OVERLAPPED
{
public:
    void InitNew(const std::function<void(DWORD errorCode)>& callback)
    {
        MANGOS_ASSERT(m_callback == nullptr);

        Internal = 0;
        InternalHigh = 0;
        Offset = 0;
        OffsetHigh = 0;
        hEvent = nullptr;
        m_callback = callback;
    }

    void Reset()
    {
        MANGOS_ASSERT(m_callback != nullptr);

        m_callback = nullptr;
    }

    void OnComplete(DWORD errorCode)
    {
        m_callback(errorCode);
    }

    std::function<void(DWORD errorCode)> m_callback = nullptr;
};

#endif //MANGOS_IO_NETWORKING_WIN32_IOCPOPERATIONEVENT_H
