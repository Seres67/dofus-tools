//
// Created by lou on 02/05/2024.
//
#include "packets/impl/ContainerInventoryContentPacket.hpp"

ContainerInventoryContentPacket::ContainerInventoryContentPacket(
    const char *packet)
    : AReceivedPacket(packet), InventoryContentPacket(packet)
{
}

std::ostream &
operator<<(std::ostream &os,
           [[maybe_unused]] const ContainerInventoryContentPacket &packet)
{
    return os << "ContainerInventoryContentPacket{}";
}
std::string ContainerInventoryContentPacket::dump() const
{
    return std::string(
        "ContainerInventoryContentPacket{id: " + std::to_string(m_packet_id) +
        "; inv_size: " + std::to_string(m_inventory_size) +
        ", kamas: " + std::to_string(m_kamas) + "}");
}
