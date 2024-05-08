//
// Created by lou on 03/05/2024.
//

#ifndef CONAN_TEST_CHATSERVERWITHOBJECTMESSAGE_CPP
#define CONAN_TEST_CHATSERVERWITHOBJECTMESSAGE_CPP

#include <ostream>
#include "packets/AReceivedPacket.hpp"

class ChatServerWithObjectMessage : virtual public AReceivedPacket {
public:
    explicit ChatServerWithObjectMessage(const char *packet);

    ~ChatServerWithObjectMessage() override = default;

    [[nodiscard]] std::string dump() const override;

    friend std::ostream &operator<<(std::ostream &os, const ChatServerWithObjectMessage &packet);

private:
    uint16_t m_packet_id = 2066;
};

#endif //CONAN_TEST_CHATSERVERWITHOBJECTMESSAGE_CPP
