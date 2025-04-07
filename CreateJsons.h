//
// Created by Alexander Garrity on 4/3/2024.
//

#ifndef CREATEJSONS_H
#define CREATEJSONS_H
#include <json.hpp>
#include <string>
#include "NameConversions.h"
void createJsons(std::string outputDir, const std::string& filepath, nlohmann::json* jason, NameConversions* localities, NameConversions* fields);
#endif //CREATEJSONS_H
