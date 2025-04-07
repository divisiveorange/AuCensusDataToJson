//
// Created by Alexander Garrity on 4/3/2024.
//

#include "CreateJsons.h"
#include <json.hpp>
#include "NameConversions.h"
#include <filesystem>
#include <fstream>
#include "CreateJsons.h"

#include "Trie.h"
void writeJson(std::string outputDir, std::string name, nlohmann::json* jason,const std::vector<nlohmann::json*>& pointersToEnd, const std::vector<std::string>& targetLine);
std::vector<std::string> stringSplit(std::string target, char delimiter);
void withinFolder(std::string outputDir, const std::string& folderPath, nlohmann::json* jason, NameConversions* localities, NameConversions* fields);
void createJsons(std::string outputDir, const std::string& folderPath, nlohmann::json* jason, NameConversions* localities, NameConversions* fields)
{
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.path().filename().string().at(0) != '.')
        {
            withinFolder(outputDir, entry.path(), jason, localities, fields);
        }
    }
}

void withinFolder(std::string outputDir, const std::string& folderPath, nlohmann::json* jason, NameConversions* localities, NameConversions* fields)
{
    std::cout << "Reached folder " << folderPath << std::endl;
    std::vector<std::filesystem::directory_entry> files = std::vector<std::filesystem::directory_entry>();
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.path().filename().string().at(0) != '.')
        {
            if (entry.is_directory())
            {
                withinFolder(outputDir, entry.path().string(), jason, localities, fields);
            } else
            {
                files.push_back(entry);
            }
        }
    }
    if (files.empty())
    {
        std::cout << "Finished with folder " << folderPath << std::endl;
        return;
    }
    std::ifstream counterStream(files.front());
    std::string counterLine;
    std::getline(counterStream, counterLine);
    auto streamVector = std::vector<std::unique_ptr<std::ifstream>>();
    for (const auto& file : files)
    {
        streamVector.push_back(std::make_unique<std::ifstream>(file));
    }
    std::vector<std::string> topLine;
    for (const auto& stream : streamVector)
    {
        std::string line;
        std::getline(*stream, line);
        auto split = stringSplit(line, ',');
        for (int i = 1; i < split.size(); i++)
        {
            topLine.emplace_back(split[i]);
        }
    }
    std::vector<std::string> convertedFields;
    for (auto field : topLine)
    {
        auto ErrCount = 0;
        tryAgain:
        try
        {
            convertedFields.emplace_back(fields->getLong(field));
        } catch (const std::out_of_range& e)
        {
            std::string newField = "";
            for (auto chary : field)
            {
                if (chary >= '!' && chary <= '~')
                {
                    newField.push_back(chary);
                }
            }
            field = newField;
            ErrCount++;
            if (ErrCount < 2) goto tryAgain;
            std::cout << field << "still not found" << std::endl;
        }
    }
    std::vector<nlohmann::json*> pointersToEnds;
    auto map = getMapToEnd(jason);
    for (auto field : convertedFields)
    {
        try
        {
            pointersToEnds.push_back(map.at(field));
        } catch (const std::out_of_range& e)
        {
            std::cerr << field << std::endl;
        }
    }
    while (std::getline(counterStream, counterLine))
    {
        std::vector<std::string> wholeLine;
        std::string name;
        for (const auto& stream : streamVector)
        {
            std::string line;
            std::getline(*stream, line);
            auto split = stringSplit(line, ',');
            for (int i = 1; i < split.size(); i++)
            {
                wholeLine.push_back(split[i]);
            }
            name = split[0];
        }
        writeJson(outputDir, localities->getLong(name), jason, pointersToEnds, wholeLine);
    }
    std::cout << "Finished with folder " << folderPath << std::endl;
 }
void writeJson(std::string outputDir, std::string name, nlohmann::json* jason, const std::vector<nlohmann::json*>& pointersToEnd, const std::vector<std::string>& targetLine)
{
    for (int i = 0; i < pointersToEnd.size(); i++)
    {
        try
        {
            *pointersToEnd[i] = std::stod(targetLine.at(i));
        } catch (const std::invalid_argument& e)
        {
            *pointersToEnd[i] = "..";
        }
    }
    std::ofstream outputFile(outputDir + "/" + name + ".json");
    auto tryCount = 0;
    tryAgainSpot:
    if (outputFile.is_open()) {
        outputFile << *jason << std::endl;
        outputFile.close();
    }  else {
        auto dirName = stringSplit(name, '/')[0];
        std::filesystem::create_directories(outputDir + "/" + dirName);
        std::cout << outputDir + "/" + dirName << std::endl;
        tryCount++;
        if (tryCount < 2) goto tryAgainSpot;
        std::cerr << "Error opening file. ../jsonFiles/" + name + ".json" << std::endl;
    }
}


std::vector<std::string> stringSplit(std::string target, char delimiter)
{
    std::vector<std::string> vec = std::vector<std::string>();
    vec.push_back("");
    for (auto chary : target)
    {
        if (chary == delimiter)
        {
            vec.emplace_back("");
        } else
        {
            vec.back().push_back(chary);
        }
    }
    return vec;
}
