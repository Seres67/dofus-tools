//
// Created by lou on 01/05/2024.
//

#include <string>
#include "packets/impl/MapMovementPacket.hpp"

MapMovementPacket::MapMovementPacket(const char *packet) : AReceivedPacket(packet) {
    m_movement_size = Utils::readUShort(packet, m_pos);
    for (int i = 0; i < m_movement_size; ++i) {
        m_moves.emplace_back(Utils::readUShort(packet, m_pos));
    }
    m_direction = Utils::readUShort(packet, m_pos);
    m_actor_id = Utils::readULong(packet, m_pos);
}

std::ostream &operator<<(std::ostream &os, const MapMovementPacket &packet) {
    os << "MapMovementPacket{size: " << packet.m_movement_size << "; moves: ";
    for (auto &&move: packet.m_moves)
        os << move << ", ";
    return os << "}";
}

std::string MapMovementPacket::dump() const {
    std::string str("MapMovementPacket{id: " + std::to_string(m_packet_id) + "; nb_moves: " + std::to_string(m_movement_size) + "; moves: ");
    for (auto &&move: m_moves)
        str += std::to_string(move) + ", ";
    str += "}";
    return str;
}
