//
// Created by Seres67 on 05/05/2024.
//

#ifndef DOFUS_SNIFFER_RESOURCEMANAGER_HPP
#define DOFUS_SNIFFER_RESOURCEMANAGER_HPP

#include <cstdint>
#include <nlohmann/json.hpp>
#include <unordered_map>

class ResourceManager
{
  public:
    ResourceManager();
    ~ResourceManager();

    std::string_view get_item_name(uint32_t item_id);

  private:
    std::unordered_map<uint32_t, uint32_t> m_items;
    std::unordered_map<uint32_t, std::string> m_names;
};

#endif // DOFUS_SNIFFER_RESOURCEMANAGER_HPP
