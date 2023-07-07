#ifndef FLOAT_TO_HEX_FLOATTOHEXCONVERTER_H
#define FLOAT_TO_HEX_FLOATTOHEXCONVERTER_H

#include "ConverterUtils.h"

#include <tuple>
#include <cstdint>

class FloatToHexConverter {
public:
    FloatToHexConverter() = default;
    ~FloatToHexConverter() = default;

    std::pair<ConverterStatus, std::array<std::uint8_t, 4>> getHexFromFloat(float value_to_convert);
};

#endif //FLOAT_TO_HEX_FLOATTOHEXCONVERTER_H