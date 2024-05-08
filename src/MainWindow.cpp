//
// Created by Seres67 on 05/05/2024.
//
#include "MainWindow.hpp"
#include "PacketCapture.hpp"
#include "packets/IPacket.hpp"
#include "packets/factory/PacketFactory.hpp"
#include <iostream>

MainWindow::MainWindow()
    : Fl_Window(800, 600, "Dofus tools"),
      m_capture(std::make_shared<PacketCapture>(this))
{
    m_start.callback(
        [](Fl_Widget *sender, void *window)
        {
            reinterpret_cast<MainWindow *>(window)->m_debug.copy_label(
                "started capture");
            reinterpret_cast<MainWindow *>(window)->m_capture->start_capture();
        },
        this);
    m_end.callback(
        [](Fl_Widget *sender, void *window)
        {
            reinterpret_cast<MainWindow *>(window)->m_debug.copy_label(
                "stopped capture");
            reinterpret_cast<MainWindow *>(window)->m_capture->stop_capture();
        },
        this);
    m_clear.callback(
        [](Fl_Widget *sender, void *window)
        { reinterpret_cast<MainWindow *>(window)->m_list.clear(); }, this);
    m_list.callback(
        [](Fl_Widget *sender, void *data)
        {
            auto *browser = dynamic_cast<Fl_Hold_Browser *>(sender);
            int index = browser->value();
            if (index < 0)
                return;
            auto *buffer = static_cast<uint8_t *>(browser->data(index));
            if (!buffer)
                return;
            auto dofus_packet = PacketFactory::make_packet(
                reinterpret_cast<const char *>(buffer));
            if (dofus_packet->getPacketId() == 1606) {
                uint16_t header = buffer[0] << 8 | buffer[1];
                std::cout << "header: " << header << std::endl;
                auto inventory =
                    dynamic_cast<InventoryContentPacket *>(dofus_packet.get())
                        ->getInventoryContent();
                for (const auto &item : inventory)
                    std::cout << item.dump() << std::endl;
            }
            std::cout << (dofus_packet)->dump() << std::endl;
        });
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < m_list.size(); ++i) {
        free(m_list.data(i));
    }
}

void MainWindow::add_debug_text(const char *text, uint8_t *packet)
{
    m_list.add(text, packet);
}
