#include "FloatToHexConverter.h"

#include <iostream>

std::pair<ConverterStatus, std::array<std::uint8_t, 4>> FloatToHexConverter::getHexFromFloat(float value_to_convert) {
    if (std::to_string(value_to_convert) == "nan" || std::to_string(value_to_convert) == "inf" ||
    std::to_string(value_to_convert) == "-inf") {
        std::cout << "input error\n";
        return std::make_pair(ConverterStatus::INVALID_ARGUMENT, std::array<std::uint8_t, 4>{0xFF, 0xFF,
                                                                                             0xFF, 0xFF});
    }


    std::cout << "values are ok\n";
}
