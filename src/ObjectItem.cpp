//
// Created by lou on 01/05/2024.
//

#include <iostream>
#include <string>
#include "ObjectItem.hpp"
#include "Utils.hpp"

ObjectItem::ObjectItem(const char *buffer, std::size_t &pos) {
    m_position = (uint8_t) buffer[pos] << 8 | (uint8_t) buffer[pos + 1];
    pos += 2;
    m_gid = Utils::readVarULong(buffer, pos);
    m_nb_effects = (uint8_t) buffer[pos] << 8 | (uint8_t) buffer[pos + 1];
    pos += 2;
    int i = 0;
    for (; i < m_nb_effects; ++i) {
        m_effects.emplace_back(buffer, pos);
    }
    m_uid = Utils::readVarULong(buffer, pos);
    m_quantity = Utils::readVarULong(buffer, pos);
    m_favorite = (uint8_t) buffer[pos];
    ++pos;
}

std::string ObjectItem::dump() const {
    return "ObjectItem{pos: " + std::to_string(m_position) + "; nb_effects: " + std::to_string(m_nb_effects) + "; gid: " + std::to_string(m_gid) +
           "; quantity: " + std::to_string(m_quantity) + "}";
}
