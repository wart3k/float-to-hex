#include "ConvertData.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <utility>

using floatConv = union {
    std::uint32_t i;
    float f;
};

ConverterData::ConverterData() = default;

ConverterData::~ConverterData() = default;

std::pair<ConverterStatus, std::string> ConverterData::convertFloatToHex(const std::string &value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    retVal = ConverterData::checkFloatReadString(value);

    try {
        auto convertVal = floatConv {.i = UINT32_MAX};
        auto stringStr = std::stringstream();

        convertVal.f = std::stof(retVal.second);

        if(convertVal.i == 0) {
            stringStr << "0x00000000";
        } else {
            stringStr << "0x" << std::hex << convertVal.i;
        }

        retVal.first = ConverterStatus::OK;
        retVal.second = stringStr.str();

    } catch (std::invalid_argument const &e) {
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
    } catch (std::out_of_range const &e) {
        retVal.first = ConverterStatus::OUT_OF_RANGE;
    }


    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::convertHexToFloat(const std::string &value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    auto convertVal = floatConv {.i = UINT32_MAX};
    auto stringStr = std::stringstream();
    char *p_end{};

    retVal = ConverterData::checkHexReadString(value);

    convertVal.i = strtoul(retVal.second.c_str(), &p_end, 16);

    if(retVal.second.c_str() == p_end) {
        std::cout << "FLOAT_TO_HEX ERROR: invalid argument, error \n";
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
        return retVal;
    }

    const bool range_error = errno == ERANGE;
    const std::string extracted(retVal.second.c_str(), p_end - retVal.second.c_str());

    if (range_error || retVal.second.size() > 10) {
        std::cout << "FLOAT_TO_HEX ERROR: out of range, error \n";
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        return retVal;
    }

    retVal.second = std::to_string(convertVal.f);

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkHexReadString(std::string readVal) {

    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    retVal.first = ConverterStatus::INVALID_ARGUMENT;
    retVal.second = std::move(readVal);

    retVal = ConverterData::removeWhitespaces(retVal.second);

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkFloatReadString(std::string readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    retVal.second = std::move(readVal);

    retVal = ConverterData::removeWhitespaces(retVal.second);

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::removeWhitespaces(const std::string& readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    retVal.second = readVal;

    try {
        retVal.second.erase(std::remove(retVal.second.begin(), retVal.second.end(), ' '),
                            retVal.second.end());

        retVal.first = ConverterStatus::OK;
    } catch (std::invalid_argument const &e) {
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
    }

    return retVal;
}
