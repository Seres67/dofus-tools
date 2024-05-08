//
// Created by Seres67 on 05/05/2024.
//

#include "ResourceManager.hpp"
#include <fstream>
#include <iostream>

ResourceManager::ResourceManager()
{
    std::ifstream items_json(
        R"(C:\Users\lou\CLionProjects\conan_test\standalone\resources\Items.json)");
    if (items_json.is_open()) {
        std::cout << "opened file" << std::endl;
        //        std::cout << items_json.rdbuf() << std::endl;
        nlohmann::json data = nlohmann::json::parse(items_json, nullptr, false);
        for (auto &&d : data["data"]) {
            m_items[d["id"]] = d["nameId"];
        }
    }
    std::ifstream names_json(
        R"(C:\Users\lou\CLionProjects\conan_test\standalone\resources\i18n_fr.json)");
    if (names_json.is_open()) {
        std::cout << "opened file" << std::endl;
        //        std::cout << items_json.rdbuf() << std::endl;
        nlohmann::json data = nlohmann::json::parse(names_json, nullptr, false);
        for (auto &&d : data.items()) {
            auto key = std::stoi(d.key());
            m_names[key] = d.value();
        }
    }
}

ResourceManager::~ResourceManager() {}

std::string_view ResourceManager::get_item_name(uint32_t item_id)
{
    return m_names[m_items[item_id]];
}
