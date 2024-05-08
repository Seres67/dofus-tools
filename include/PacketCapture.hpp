//
// Created by Seres67 on 05/05/2024.
//

#ifndef DOFUS_SNIFFER_PACKETCAPTURE_HPP
#define DOFUS_SNIFFER_PACKETCAPTURE_HPP

#define _WINSOCK2API_

#include <FL/Fl_Window.H>
#include <PcapLiveDevice.h>
#include <PcapLiveDeviceList.h>
#include <TcpReassembly.h>
#include <memory>

class MainWindow;

class PacketCapture
{
  public:
    explicit PacketCapture(MainWindow *window);
    ~PacketCapture();
    void start_capture();
    void stop_capture();

  private:
    std::shared_ptr<pcpp::PcapLiveDevice> m_dev;
    pcpp::TcpReassembly m_tcp_reassembly;
    static MainWindow *m_window;
    static void on_packet_arrives(pcpp::RawPacket *packet,
                                  pcpp::PcapLiveDevice *dev,
                                  void *tcpReassemblyCookie);
    static void
    tcp_reassembly_msg_meady_callback(const int8_t sideIndex,
                                      const pcpp::TcpStreamData &tcpData,
                                      void *userCookie);
};

#endif // DOFUS_SNIFFER_PACKETCAPTURE_HPP
