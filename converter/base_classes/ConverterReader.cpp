#include <fstream>
#include <istream>

#include "ConverterReader.h"

std::pair<ConverterReadStatus, std::string> ConverterReader::readLine(const std::string &path, std::uint32_t lineNr) {

    auto retVal = std::pair<ConverterReadStatus, std::string>{ConverterReadStatus::OK, ""};

    if(lineNr >= UINT32_MAX) {
        retVal.first = ConverterReadStatus::LENGTH_ERROR;
        return retVal;
    }

    auto lineSearchVar = std::uint32_t {0 };
    auto iffile = std::ifstream{};

    iffile.open(path);

    if(iffile.is_open()) {

        while(std::getline(iffile, retVal.second)) {
            if(lineNr == lineSearchVar)
                break;

            ++lineSearchVar;

            if(lineSearchVar >= UINT32_MAX) {
                retVal.first = ConverterReadStatus::LENGTH_ERROR;
                retVal.second = "";
                iffile.close();
                return retVal;
            }
        }

        if(lineNr > lineSearchVar)
            retVal.first = ConverterReadStatus::SEARCHED_LINE_IS_HIGHER_THAN_MAX;
    }

    else
        retVal.first = ConverterReadStatus::FILE_READING_ERROR;

    iffile.close();
    return retVal;
}

std::pair<ConverterReadStatus, std::uint32_t> ConverterReader::getMaxLineNr(const std::string &path) {
    auto retVal = std::pair<ConverterReadStatus, std::uint32_t>{ConverterReadStatus::OK, std::uint32_t { UINT32_MAX }};

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

    }

    iffile.close();
    return retVal;
}



