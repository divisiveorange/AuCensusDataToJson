//
// Created by Alexander Garrity on 27/2/2024.
//

#include "Trie.h"
void getMapToEndRec(nlohmann::json* jason, std::string nameTillNow, std::map<std::string, nlohmann::json*>* map);
std::map<std::string, nlohmann::json*> getMapToEnd(nlohmann::json* jason)
{
    auto map = new std::map<std::string, nlohmann::json*>();
    for (auto it = jason->begin(); it != jason->end(); ++it)
    {
        if (!it->is_object())
        {
            map->insert({it.key(), &it.value()});
            continue;
        }
        getMapToEndRec(&jason->at(it.key()), it.key(), map);;
    }
    auto returnable = *map;
    delete map;
    return returnable;
}
void getMapToEndRec(nlohmann::json* jason, std::string nameTillNow, std::map<std::string, nlohmann::json*>* map)
{
    for (auto it = jason->begin(); it != jason->end(); ++it)
    {
        if (!it->is_object())
        {
            map->insert({nameTillNow + it.key(), &jason->at(it.key())});
            continue;
        }
        getMapToEndRec(&jason->at(it.key()), nameTillNow + it.key(), map);;
    }
}
