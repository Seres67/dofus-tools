//
// Created by lou on 02/05/2024.
//

#include "Utils.hpp"
#include <iostream>

uint64_t Utils::readVarULong(const char *buffer, std::size_t &pos)
{
    uint64_t out = 0;
    int i = 0;
    for (; i < 8; ++i) {
        if (buffer[pos + i] & 0x80) {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
        } else {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
            pos += i + 1;
            return out;
        }
    }
    pos += i;
    return out;
}

uint32_t Utils::readVarUInt(const char *buffer, std::size_t &pos)
{
    uint32_t out = 0;
    int i = 0;
    for (; i < 4; ++i) {
        if (buffer[pos + i] & 0x80) {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
        } else {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
            pos += i + 1;
            return out;
        }
    }
    pos += i;
    return out;
}

uint16_t Utils::readVarUShort(const char *buffer, std::size_t &pos)
{
    uint16_t out = 0;
    int i = 0;
    for (; i < 2; ++i) {
        if (buffer[pos + i] & 0x80) {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
        } else {
            out |= (uint8_t)buffer[pos + i] << (i * 8 - i);
            pos += i + 1;
            return out;
        }
    }
    pos += i;
    return out;
}

uint64_t Utils::readULong(const char *buffer, std::size_t &pos)
{
    uint64_t out = 0;
    memcpy(&out, &buffer[pos], sizeof(uint64_t));
    pos += sizeof(uint64_t);
    return out;
}

uint32_t Utils::readUInt(const char *buffer, std::size_t &pos)
{
    pos += 4;
    return (uint8_t)buffer[pos] << 24 | (uint8_t)buffer[pos + 1] << 16 |
           (uint8_t)buffer[pos + 2] << 8 | (uint8_t)buffer[pos + 3];
}

uint16_t Utils::readUShort(const char *buffer, std::size_t &pos)
{
    pos += 2;
    return (uint8_t)buffer[pos] << 8 | (uint8_t)buffer[pos + 1];
}

#include <climits>

template <typename T> [[maybe_unused]] T Utils::swap_endian(T u)
{
    static_assert(CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}
