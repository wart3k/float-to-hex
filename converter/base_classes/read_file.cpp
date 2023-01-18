#include <fstream>
#include <istream>

#include "read_file.h"

ConverterReader::ConverterReader() = default;

ConverterReader::~ConverterReader() = default;

std::pair<ConverterReadStatus, std::string> ConverterReader::readLine(const std::string &path, std::uint32_t lineNr) {

    auto retVal = std::pair<ConverterReadStatus, std::string>{ConverterReadStatus::OK, ""};

    if(lineNr >= UINT32_MAX) {
        retVal.first = ConverterReadStatus::LENGTH_ERROR;
        return retVal;
    }

    auto rowNum = std::uint32_t { 0 };
    auto iffile = std::ifstream{};

    iffile.open(path);

    if(iffile.is_open()) {

        while(std::getline(iffile, retVal.second)) {
            if(lineNr == rowNum)
                break;

            ++rowNum;
        }

        if(lineNr > rowNum)
            retVal.first = ConverterReadStatus::SEARCHED_LINE_IS_HIGHER_THAN_MAX;
    }

    else
        retVal.first = ConverterReadStatus::FILE_READING_ERROR;

    iffile.close();
    return retVal;
}

std::pair<ConverterReadStatus, std::uint32_t> ConverterReader::getMaxLineNr(const std::string &path) {
    auto retVal = std::pair<ConverterReadStatus, std::uint32_t>{ConverterReadStatus::OK, std::uint32_t { 0 }};

    auto str = std::string{};
    auto iffile = std::ifstream{};

    iffile.open(path);

    if(iffile.is_open()) {

        while (std::getline(iffile, str)) {
            ++retVal.second;
            if(retVal.second >= UINT32_MAX) {
                retVal.first = ConverterReadStatus::LENGTH_ERROR;
                retVal.second = UINT32_MAX;
                break;
            }
        }

    } else {

        retVal.first = ConverterReadStatus::FILE_READING_ERROR;
        retVal.second = std::uint32_t { 0 };

    }

    iffile.close();
    return retVal;
}



