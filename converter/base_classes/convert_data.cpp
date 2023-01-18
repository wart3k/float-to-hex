#include "convert_data.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using floatConv = union {
    std::uint32_t i;
    float f;
};

Converter::Converter() = default;

Converter::~Converter() = default;

std::pair<ConverterStatus, std::string> Converter::convertFloatToHex(const std::string& value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    try {
        auto convertVal = floatConv {.i = UINT32_MAX};
        auto stringStr = std::stringstream();

        convertVal.f = std::stof(value);
        stringStr << "0x" << std::hex << convertVal.i;

        std::cout << "float value is: " << convertVal.f << " hex val is: " << stringStr.str() << "\n";

        retVal.first = ConverterStatus::OK;
        retVal.second = stringStr.str();

    } catch (std::invalid_argument const &e) {
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
        std::cout << "FLOAT_TO_HEX ERROR: invalid argument, error:  " << e.what() << "\n";
    } catch (std::out_of_range const &e) {
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        std::cout << "FLOAT_TO_HEX ERROR: out of range, error:  " << e.what() << "\n";
    }


    return retVal;
}

std::pair<ConverterStatus, std::string> Converter::convertHexToFloat(const std::string &value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "NaN"};

    auto convertVal = floatConv {.i = UINT32_MAX};
    auto stringStr = std::stringstream();
    char *p_end{};

    convertVal.i = strtoul(value.c_str(), &p_end, 16);

    if(value.c_str() == p_end) {
        std::cout << "FLOAT_TO_HEX ERROR: invalid argument, error \n";
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
        return retVal;
    }

    const bool range_error = errno == ERANGE;
    const std::string extracted(value.c_str(), p_end - value.c_str());

    if (range_error || value.size() > 10) {
        std::cout << "FLOAT_TO_HEX ERROR: out of range, error \n";
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        return retVal;
    }

    std::cout << "Hex value is: " << std::quoted(extracted)
              << ", float value is: " << convertVal.f << "\n";

    return retVal;
}
