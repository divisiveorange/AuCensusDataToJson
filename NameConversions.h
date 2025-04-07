//
// Created by Alexander Garrity on 4/3/2024.
//

#ifndef NAMECONVERSIONS_H
#define NAMECONVERSIONS_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <ranges>
std::string runCli(std::string command);
enum PossibleConversions {LOCALITIES, FIELDS};
class NameConversions {
public:
    NameConversions(PossibleConversions conversion, std::string folderOrFilePath)
    {
        LongToShortConversionMap = std::make_unique<std::map<std::string, std::string>>();
        ShortToLongConversionMap = std::make_unique<std::map<std::string, std::string>>();
        if (conversion == LOCALITIES)
        {
            auto areaShortCommaLong = runCli("cat \"" + folderOrFilePath + "\"/*"" | cut -d, -f1 -f2 -f4");
            auto pairings = splitText(areaShortCommaLong);
            for (auto line : pairings)
            {
                auto longName = line.at(0) + "::" + line.at(2);
                auto shortName = line.at(1);
                LongToShortConversionMap->insert({longName, shortName});
                ShortToLongConversionMap->insert({shortName, longName});

            }
        }
        else if (conversion == FIELDS)
        {
            std::string command = "tail -n +12 '" + folderOrFilePath + "/Cell Descriptors Information-Table 1.csv" + "' | cut -d, -f2 -f3 -f5 | sed -E 's/[^0-9]*$//g'";
            auto shortLong = runCli(command);
            auto pairings = splitText(shortLong);
            command = "tail -n +10 '" + folderOrFilePath + "/Table Number, Name, Population-Table 1.csv" + "' | cut -d, -f1-2 ";
            auto fieldCategories = runCli(command);
            auto questionType = splitText(fieldCategories);
            std::map<std::string, std::string> questionMap;
            for (auto line : questionType)
            {
                questionMap.insert({line[0], line[1]});
            }
            for (auto line : pairings)
            {
                auto longname = questionMap.at(line[2]) + ":_" + line[1];
                LongToShortConversionMap->insert({longname, line[0]});
                ShortToLongConversionMap->insert({line[0], longname});
            }
        }
    }
    std::string getLong(std::string shortName)
    {
        return ShortToLongConversionMap->at(shortName);
    }
    std::string getShort(std::string longName)
    {
        return LongToShortConversionMap->at(longName);
    }
    std::vector<std::string> getLongs()
    {
        auto keys_view = *LongToShortConversionMap | std::views::keys;
        std::vector<std::string> keys(keys_view.begin(), keys_view.end());
        return keys;
    }
    std::vector<std::string> getShorts()
    {
        auto keys_view = *ShortToLongConversionMap | std::views::keys;
        std::vector<std::string> keys(keys_view.begin(), keys_view.end());
        return keys;
    }
    static std::vector<std::vector<std::string>> splitText(std::string text)
    {
        auto lines = std::vector<std::string>();
        std::stringstream ss(text);
        std::string line;
        while (std::getline(ss, line, '\n')) {
            lines.push_back(line);
        }
        std::vector<std::vector<std::string>> pairings;
        for (auto line : lines)
        {
            std::stringstream ss(line);
            std::string part;
            std::vector<std::string> parts;
            while (std::getline(ss, part, ',')) {
                parts.push_back(part);
            }
            pairings.push_back(parts);
        }
        return pairings;
    }
protected:
    std::unique_ptr<std::map<std::string, std::string>> LongToShortConversionMap;
    std::unique_ptr<std::map<std::string, std::string>> ShortToLongConversionMap;
};



#endif //NAMECONVERSIONS_H
