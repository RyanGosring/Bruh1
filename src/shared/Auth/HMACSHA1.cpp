/*
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Auth/HMACSHA1.h"
#include "BigNumber.h"

HMACSHA1::HMACSHA1(const uint8* seed, size_t len)
{
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x30000000L
    m_mac = EVP_MAC_fetch(nullptr, "HMAC", nullptr);
    m_ctx = EVP_MAC_CTX_new(m_mac);

    OSSL_PARAM params[2];
    params[0] = OSSL_PARAM_construct_utf8_string("digest", const_cast<char*>("SHA1"), 0);
    params[1] = OSSL_PARAM_construct_end();

    EVP_MAC_init(m_ctx, seed, len, params);
#else
    m_ctx = HMAC_CTX_new();
    HMAC_Init_ex(m_ctx, seed, len, EVP_sha1(), nullptr);
#endif
}

HMACSHA1::~HMACSHA1()
{
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x30000000L
    EVP_MAC_CTX_free(m_ctx);
    EVP_MAC_free(m_mac);
#else
    HMAC_CTX_free(m_ctx);
#endif
}

void HMACSHA1::UpdateBigNumber(BigNumber* bn)
{
    UpdateData(bn->AsByteArray());
}

void HMACSHA1::UpdateData(std::vector<uint8> const& data)
{
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x30000000L
    EVP_MAC_update(m_ctx, data.data(), data.size());
#else
    HMAC_Update(m_ctx, data.data(), data.size());
#endif
}

void HMACSHA1::UpdateData(uint8 const* data, int length)
{
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x30000000L
    EVP_MAC_update(m_ctx, data, length);
#else
    HMAC_Update(m_ctx, data, length);
#endif
}

void HMACSHA1::UpdateData(std::string const& str)
{
    UpdateData(reinterpret_cast<const uint8*>(str.c_str()), str.length());
}

void HMACSHA1::Finalize()
{
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x30000000L
    size_t length = 0;
    EVP_MAC_final(m_ctx, m_digest, &length, sizeof(m_digest));
#else
    uint32 length = 0;
    HMAC_Final(m_ctx, (uint8*)m_digest, &length);
#endif
    //MANGOS_ASSERT(length == SHA_DIGEST_LENGTH);

}

uint8* HMACSHA1::ComputeHash(BigNumber* bn)
{
    auto byteArray = bn->AsByteArray();
    UpdateData(byteArray.data(), byteArray.size());
    Finalize();
    return (uint8*)m_digest;
}
