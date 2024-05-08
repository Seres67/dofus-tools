//
// Created by lou on 01/05/2024.
//

#include "packets/impl/InventoryContentPacket.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>

InventoryContentPacket::InventoryContentPacket(const char *packet)
    : AReceivedPacket(packet)
{
    m_inventory_size = Utils::readUShort(packet, m_pos);
    for (int i = 0; i < m_inventory_size; ++i) {
        m_inventory_content.emplace_back(packet, m_pos);
    }
    m_kamas = Utils::readVarULong(packet, m_pos);
}

std::ostream &operator<<(std::ostream &os, const InventoryContentPacket &packet)
{
    return os << "InventoryContentPacket{size: " << packet.m_inventory_size
              << "}";
}

std::string InventoryContentPacket::dump() const
{
    return std::string(
        "InventoryContentPacket{id: " + std::to_string(m_packet_id) +
        "; len: " + std::to_string(getLength()) +
        "; inv_size: " + std::to_string(m_inventory_size) +
        ", kamas: " + std::to_string(m_kamas) + "}");
}

const std::vector<ObjectItem> &
InventoryContentPacket::getInventoryContent() const
{
    return m_inventory_content;
}
