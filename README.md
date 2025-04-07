This is a Macos and Unix program (requires the Unix tool, cut) for converting the CSV files provided by the ABS for the 2021 Australian census to collection of json files for each region in the data. 
This program can be build by running "make" within the build directory.
Census data can be aquired from https://www.abs.gov.au/census/find-census-data/datapacks.
While most of this data is in CSV format, within the metadata format, there are .xlsx files which must be converted to a folder of csvs (I used MacOS Numbers).

To run the program, within the main folder run
./build/Parsing {path to "2021 Census GCP..." folder} {folder for json files to be written} {path to Metadata_2021_GCP_DataPack_R1_R2 folder} {path to 2021Census_geog_desc folder} 

or use the included small scale data with 

./build/Parsing "SmallCensusData/2021 Census GCP All Geographies for OT" jsonFiles SmallCensusData/Metadata_2021_GCP_DataPack_R1_R2 SmallCensusData/2021Census_geog_desc_1st_2nd_3rd_release

Specifically what this does and why:

In addition to json being a more easily transformable data format, one major thing this project achieves is being easier to read and understand data for a specific region since in the census' data format, the human understandable name of a data point lies on a different file to where the data lies (yes, it was clearly converted from an sql database).

This was written in C++ due to it's speed but also that, since the census data is not updated regularly and new updates could break this program, this program is only designed to be run on someone's computer, not a public facing server with unknown inputs, security is not a large concern. 
