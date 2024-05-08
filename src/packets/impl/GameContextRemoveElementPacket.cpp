//
// Created by lou on 01/05/2024.
//
#include <string>
#include "packets/impl/GameContextRemoveElementPacket.hpp"

GameContextRemoveElementPacket::GameContextRemoveElementPacket(const char *packet) : AReceivedPacket(packet) {
    m_element_id = Utils::readUShort(packet, m_pos);
}

std::ostream &operator<<(std::ostream &os, [[maybe_unused]] const GameContextRemoveElementPacket &packet) {
    return os << "GameContextRemoveElementPacket{}";
}

std::string GameContextRemoveElementPacket::dump() const {
    return std::string("GameContextRemoveElementPacket{id: " + std::to_string(m_element_id) + "}");
}
