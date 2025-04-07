#include <iostream>
#include "Trie.h"
#include <vector>
#include <cassert>
#include <json.hpp>
#include "NameConversions.h"
#include "CreateJsons.h"

int main(int argc, char *argv[])
{
    std::string sourceDir;
    std::string outputDir;
    std::string fieldDescriptionFile;
    std::string geographyDescriptionFolder;
    if (argc < 2)
    {
        sourceDir = "../2021_GCP_all_for_AUS_short-header/2021 Census GCP All Geographies for AUS";
    } else
    {
        sourceDir = argv[1];
    }
    if (argc < 3)
    {
        outputDir = "../jsonFiles";
    } else
    {
        outputDir = argv[2];
    }
    if (argc < 5)
    {
        fieldDescriptionFile = "../2021_GCP_all_for_AUS_short-header/Metadata/Metadata_2021_GCP_DataPack_R1_R2";
        geographyDescriptionFolder = "../2021_GCP_all_for_AUS_short-header/Metadata/2021Census_geog_desc_1st_2nd_3rd_release";
    } else
    {
        fieldDescriptionFile = argv[3];
        geographyDescriptionFolder = argv[4];
    }
    auto localities = new NameConversions(LOCALITIES, geographyDescriptionFolder);
    auto fields = new NameConversions(FIELDS, fieldDescriptionFile);
    auto shorts = fields->getShorts();
    auto trie = Trie();
    auto longFields = fields->getLongs();
    for (auto name : longFields)
    {
        trie.add(name);
    }
    trie.combine();
    auto jason = trie.getJson();
    createJsons(outputDir, sourceDir, jason, localities, fields);
    delete localities;
    delete fields;
    delete jason;
}
