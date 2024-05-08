//
// Created by Seres67 on 05/05/2024.
//

#include "MainWindow.hpp"
#include "packets/PacketNames.hpp"
#include <FL/Fl.H>

auto main(int argc, char *argv[]) -> int
{
    PacketNames::setup_map();
    auto window = MainWindow{};
    window.show(argc, argv);
    int out = Fl::run();
    return out;
}