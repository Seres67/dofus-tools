//
// Created by lou on 01/05/2024.
//

#ifndef DOFUS_TEST_PLAYERINVENTORYPACKET_HPP
#define DOFUS_TEST_PLAYERINVENTORYPACKET_HPP

#include "ObjectItem.hpp"
#include "packets/AReceivedPacket.hpp"
#include <cstdint>
#include <ostream>
#include <vector>

class InventoryContentPacket : virtual public AReceivedPacket
{
  public:
    explicit InventoryContentPacket(const char *packet);

    ~InventoryContentPacket() override = default;

    [[nodiscard]] std::string dump() const override;

    friend std::ostream &operator<<(std::ostream &os,
                                    const InventoryContentPacket &packet);
    const std::vector<ObjectItem> &getInventoryContent() const;

  private:
    uint16_t m_packet_id = 8307;

  protected:
    uint16_t m_inventory_size;
    std::vector<ObjectItem> m_inventory_content;
    uint64_t m_kamas;
};

#endif // DOFUS_TEST_PLAYERINVENTORYPACKET_HPP
