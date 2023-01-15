#include <iostream>
#include <fstream>
#include <istream>

#include "read_file.h"

ConverterReader::ConverterReader() = default;

ConverterReader::~ConverterReader() = default;

void ConverterReader::readValue(const std::string& path) {
    auto str = std::string{};
    auto iffile = std::ifstream{};
    auto rowNum = 0LU;

    iffile.open(path);

    if(iffile.is_open()) {
        while(std::getline(iffile, str)) {
            ++rowNum;
        }
        std::cout << "Found " << rowNum << " rows\n";
    }

    else {
        std::cout << "Can´t open file\n";
    }
    iffile.close();
}



