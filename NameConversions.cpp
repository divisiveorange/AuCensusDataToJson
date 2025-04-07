//
// Created by Alexander Garrity on 4/3/2024.
//

#include "NameConversions.h"

std::string runCli(std::string command)
{
    std::string output;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error: Couldn't open pipe for command execution.\n";
        return "";
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        output += buffer;
    }
    pclose(pipe);
    return output;
}