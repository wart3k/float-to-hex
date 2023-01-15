#include "converter.h"

#include <stdexcept>
#include <iostream>
#include <sstream>

using floatConv = union {
    std::uint32_t i;
//    std::uint8_t b[4];
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
