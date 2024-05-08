//
// Created by lou on 02/05/2024.
//

#include "ObjectEffect.hpp"
#include "Utils.hpp"
#include <iostream>

ObjectEffect::ObjectEffect(const char *buffer, std::size_t &pos)
{
    m_effect_id = (uint8_t) buffer[pos] << 8 | (uint8_t) buffer[pos + 1];
    pos += 2;
    if (m_effect_id == 5722) { // integer effect
        Utils::readVarUShort(buffer, pos);
        Utils::readVarULong(buffer, pos);
    } else if (m_effect_id == 5097) { // dice effect
        Utils::readVarUShort(buffer, pos);
        Utils::readVarULong(buffer, pos);
        Utils::readVarULong(buffer, pos);
        Utils::readVarULong(buffer, pos);
    }
}

ObjectEffect::ObjectEffect(uint16_t effect_id) : m_effect_id(effect_id) {}
