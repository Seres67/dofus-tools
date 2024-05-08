//
// Created by Seres67 on 05/05/2024.
//

#ifndef DOFUS_SNIFFER_MAINWINDOW_HPP
#define DOFUS_SNIFFER_MAINWINDOW_HPP

#include "ResourceManager.hpp"
#include "packets/IPacket.hpp"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Window.H>
#include <memory>

class PacketCapture;

class MainWindow : public Fl_Window
{
  public:
    MainWindow();
    ~MainWindow() override;

    void add_debug_text(const char *text, uint8_t *packet);

  private:
    Fl_Button m_start{0, 0, 100, 20, "Start"};
    Fl_Button m_end{100, 0, 100, 20, "End"};
    Fl_Button m_clear{200, 0, 100, 20, "Clear"};
    Fl_Box m_debug{0, 440, 800, 100, "idle"};
    Fl_Hold_Browser m_list{0, 40, 800, 400};
    std::shared_ptr<PacketCapture> m_capture;
    ResourceManager m_resource_manager;
};

#endif // DOFUS_SNIFFER_MAINWINDOW_HPP
