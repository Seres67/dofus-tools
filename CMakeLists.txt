cmake_minimum_required(VERSION 3.28)
project(standalone)

set(CMAKE_CXX_STANDARD 23)

find_package(FLTK CONFIG REQUIRED)
find_package(PcapPlusPlus CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(standalone WIN32)
target_sources(standalone PRIVATE src/main.cpp src/MainWindow.cpp src/ObjectEffect.cpp
        src/ObjectItem.cpp
        src/packets/PacketNames.cpp
        src/packets/impl/BasicAckPacket.cpp
        src/packets/impl/BasicPingPacket.cpp
        src/packets/impl/BasicPongPacket.cpp
        src/packets/impl/ChatMessagePacket.cpp
        src/packets/impl/ContainerInventoryContentPacket.cpp
        src/packets/impl/ExchangeBidHouseSearchMessage.cpp
        src/packets/impl/GameContextRemoveElementPacket.cpp
        src/packets/impl/MapFightCountPacket.cpp
        src/packets/impl/MapMovementPacket.cpp
        src/packets/impl/MultiTabStoragePacket.cpp
        src/packets/impl/NoMovementPacket.cpp
        src/packets/impl/InventoryContentPacket.cpp
        src/packets/impl/UnknownPacket.cpp
        src/Utils.cpp
        src/packets/impl/ChatServerWithObjectMessage.cpp
        src/PacketCapture.cpp
        src/ResourceManager.cpp)

target_link_libraries(standalone PRIVATE fltk fltk_gl fltk_forms fltk_images)
target_link_libraries(standalone PRIVATE PCAP::PCAP Packet::Packet PcapPlusPlus::Pcap++ PcapPlusPlus::Common++)
target_link_libraries(standalone PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(standalone PRIVATE include)
