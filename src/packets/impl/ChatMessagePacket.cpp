//
// Created by lou on 30/04/2024.
//

#include "packets/impl/ChatMessagePacket.hpp"
#include <iostream>
#include <string>

ChatMessagePacket::ChatMessagePacket(const char *packet)
    : AReceivedPacket(packet)
{
    m_channel = packet[m_pos++];
    m_message_size = Utils::readUShort(packet, m_pos);
    uint32_t i;
    for (i = 0; i < m_message_size; ++i) {
        m_message_content.push_back(packet[m_pos + i]);
    }
    m_pos += m_message_size;
    m_timestamp = Utils::readUInt(packet, m_pos);
    m_fingerprint_size = Utils::readUShort(packet, m_pos);
    for (i = 0; i < m_fingerprint_size; ++i) {
        m_fingerprint |= (packet[m_pos + i] << (i * 8));
    }
    m_pos += m_fingerprint_size;
    m_sender_id = Utils::readULong(packet, m_pos);
    //        m_sender_id =
    //                (uint8_t) packet[m_pos + 1] << 56 | (uint8_t) packet[m_pos
    //                + 2] << 48 | (uint8_t) packet[m_pos + 3] << 40 | (uint8_t)
    //                packet[m_pos + 4] << 32 | (uint8_t) packet[m_pos + 5] <<
    //                24 | (uint8_t) packet[m_pos + 6] << 16 | (uint8_t)
    //                packet[m_pos + 7] << 8 | (uint8_t) packet[m_pos + 8];
    m_sender_name_size = Utils::readUShort(packet, m_pos);
    for (i = 0; i < m_sender_name_size; ++i) {
        m_sender_name.push_back(packet[m_pos + i]);
    }
    m_pos += m_sender_name_size;
    m_prefix_name_size = Utils::readUShort(packet, m_pos);
    if (m_prefix_name_size != 0) {
        m_pos += m_prefix_name_size;
        // todo
    }
    m_sender_account_id = Utils::readUInt(packet, m_pos);
}

std::ostream &operator<<(std::ostream &os, const ChatMessagePacket &packet)
{
    return os << "ChatMessagePacket{sender: " << packet.m_sender_name
              << "; message: " << packet.m_message_content << "}";
}

std::string ChatMessagePacket::dump() const
{
    return std::string("ChatMessagePacket{sender: " + m_sender_name +
                       "; message: " + m_message_content + "}");
}
