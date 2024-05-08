//
// Created by lou on 03/05/2024.
//
#include <string>
#include "packets/AReceivedPacket.hpp"
#include "packets/impl/ChatServerWithObjectMessage.hpp"

ChatServerWithObjectMessage::ChatServerWithObjectMessage(const char *packet) : AReceivedPacket(packet) {

}

std::ostream &operator<<(std::ostream &os, const ChatServerWithObjectMessage &packet) {
    return os << "ChatServerWithObjectMessage{}";
}

std::string ChatServerWithObjectMessage::dump() const {
    return std::string("ChatServerWithObjectMessage{id: " + std::to_string(m_packet_id) + "; len: " + std::to_string(getLength()) + "}");
}
