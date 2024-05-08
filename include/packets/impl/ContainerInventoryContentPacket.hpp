//
// Created by lou on 02/05/2024.
//

#ifndef DOFUS_TEST_CONTAINERINVENTORYPACKET_HPP
#define DOFUS_TEST_CONTAINERINVENTORYPACKET_HPP

#include "packets/impl/InventoryContentPacket.hpp"
#include <ostream>

class ContainerInventoryContentPacket : public InventoryContentPacket
{
public:
    explicit ContainerInventoryContentPacket(const char *packet);

    friend std::ostream &operator<<(std::ostream &os, const ContainerInventoryContentPacket &packet);
    std::string dump() const override;

  private:
    uint16_t m_packet_id = 1606;
};

#endif //DOFUS_TEST_CONTAINERINVENTORYPACKET_HPP
