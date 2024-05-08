//
// Created by Seres67 on 05/05/2024.
//

#include "PacketCapture.hpp"
#include "MainWindow.hpp"
#include "packets/IPacket.hpp"
#include "packets/PacketNames.hpp"
#include "packets/factory/PacketFactory.hpp"
#include <iostream>
#include <utility>

MainWindow *PacketCapture::m_window;

PacketCapture::PacketCapture(MainWindow *window)
    : m_tcp_reassembly(PacketCapture::tcp_reassembly_msg_meady_callback,
                       nullptr, nullptr, nullptr)
{
    m_dev = std::shared_ptr<pcpp::PcapLiveDevice>(
        pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(
            "192.168.1.143"));
    m_window = window;
}

void PacketCapture::start_capture()
{
    m_dev->open();
    m_dev->setFilter("port 5555");
    m_dev->startCapture(PacketCapture::on_packet_arrives, &m_tcp_reassembly);
}

void PacketCapture::stop_capture() { m_dev->stopCapture(); }

void PacketCapture::on_packet_arrives(pcpp::RawPacket *packet,
                                      pcpp::PcapLiveDevice *dev,
                                      void *tcpReassemblyCookie)
{
    auto tcpReassembly = (pcpp::TcpReassembly *)tcpReassemblyCookie;
    tcpReassembly->reassemblePacket(packet);
}

void PacketCapture::tcp_reassembly_msg_meady_callback(
    const int8_t sideIndex, const pcpp::TcpStreamData &tcpData,
    void *userCookie)
{
    const uint8_t *buffer = tcpData.getData();
    std::unique_ptr<IPacket> dofus_packet =
        PacketFactory::make_packet(reinterpret_cast<const char *>(buffer));
    //    if (dofus_packet->isFromServer())
    //        std::cout << "received " << dofus_packet->dump() << std::endl;
    //    else
    //        std::cout << "sent " << dofus_packet->dump() << std::endl;

    auto *tmp = static_cast<uint8_t *>(
        malloc(sizeof(uint8_t) * tcpData.getDataLength()));
    memcpy_s(tmp, tcpData.getDataLength(), buffer, tcpData.getDataLength());
    m_window->add_debug_text(dofus_packet->dump().c_str(), tmp);
}

PacketCapture::~PacketCapture()
{
    m_dev->stopCapture();
    m_dev->close();
}
