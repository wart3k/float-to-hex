#ifndef FLOAT_TO_HEX_CONVERTERUTILS_H
#define FLOAT_TO_HEX_CONVERTERUTILS_H

#include <cstdint>

enum class ConverterStatus {
    OK = 0,
    INVALID_ARGUMENT,
    OUT_OF_RANGE
};

using floatConv = union {
    std::uint32_t i;
    float f;
};

#endif //FLOAT_TO_HEX_CONVERTERUTILS_H
