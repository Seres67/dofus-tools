//
// Created by lou on 01/05/2024.
//

#ifndef DOFUS_TEST_GAMECONTEXTREMOVEELEMENTPACKET_HPP
#define DOFUS_TEST_GAMECONTEXTREMOVEELEMENTPACKET_HPP

#include <ostream>
#include "packets/AReceivedPacket.hpp"

class GameContextRemoveElementPacket : virtual public AReceivedPacket {
public:
    explicit GameContextRemoveElementPacket(const char *packet);

    ~GameContextRemoveElementPacket() override = default;

    [[nodiscard]] std::string dump() const override;

    friend std::ostream &operator<<(std::ostream &os, const GameContextRemoveElementPacket &packet);

private:
    uint16_t m_packet_id = 1463;
    uint16_t m_element_id;
};

#endif //DOFUS_TEST_GAMECONTEXTREMOVEELEMENTPACKET_HPP
