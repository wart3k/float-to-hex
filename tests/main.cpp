#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "ConvertData.h"

#include <tuple>
#include <string>

TEST_CASE( "Testing convert float to hex example values", "[float-to-hex-example-val]" ) {
    ConverterData testConverter;

    auto converter_pair = std::pair<ConverterStatus, std::string>{};

    /* Test cases with Status = OK and values from example */
    converter_pair.first = ConverterStatus::OK;
    converter_pair.second = "0xbfc00000";
    REQUIRE(testConverter.convertFloatToHex("-1.5") == converter_pair);

    converter_pair.second = "0xbf800000";
    REQUIRE(testConverter.convertFloatToHex("-1.0") == converter_pair);

    converter_pair.second = "0xbf000000";
    REQUIRE(testConverter.convertFloatToHex("-0.5") == converter_pair);

    converter_pair.second = "0x00000000";
    REQUIRE(testConverter.convertFloatToHex("0.0") == converter_pair);

    converter_pair.second = "0x3f000000";
    REQUIRE(testConverter.convertFloatToHex("0.5") == converter_pair);

    converter_pair.second = "0x3f800000";
    REQUIRE(testConverter.convertFloatToHex("1.0") == converter_pair);

    converter_pair.second = "0x3fc00000";
    REQUIRE(testConverter.convertFloatToHex("1.5") == converter_pair);
}

TEST_CASE( "Testing convert float to hex with whitespaces in float values", "[float-to-hex-whitespaces]" ) {
    ConverterData testConverter;

    auto converter_pair = std::pair<ConverterStatus, std::string>{};

    /* Test cases with Status = OK and values from example */
    converter_pair.first = ConverterStatus::OK;
    converter_pair.second = "0xbfc00000";
    REQUIRE(testConverter.convertFloatToHex("- 1. 5") == converter_pair);

    converter_pair.second = "0xbf800000";
    REQUIRE(testConverter.convertFloatToHex("    -1.0    ") == converter_pair);

    converter_pair.second = "0xbf000000";
    REQUIRE(testConverter.convertFloatToHex(" - 0 . 5 ") == converter_pair);

    converter_pair.second = "0x00000000";
    REQUIRE(testConverter.convertFloatToHex("0.0       ") == converter_pair);

    converter_pair.second = "0x3f000000";
    REQUIRE(testConverter.convertFloatToHex("0 .     5") == converter_pair);

    converter_pair.second = "0x3f800000";
    REQUIRE(testConverter.convertFloatToHex(" 1 .      0 ") == converter_pair);

    converter_pair.second = "0x3fc00000";
    REQUIRE(testConverter.convertFloatToHex("          1       .            5             ") == converter_pair);
}

TEST_CASE( "Testing convert hex to float with example values", "[hex-to-float-example-val]" ) {
    ConverterData testConverter;

    auto converterPair = std::pair<ConverterStatus, std::string>{};
    /* Test cases with Status = OK and values from example */
    converterPair.first = ConverterStatus::OK;
    converterPair.second = "-1.500000";
    REQUIRE(testConverter.convertHexToFloat("0xbfc00000") == converterPair);

    converterPair.second = "-1.000000";
    REQUIRE(testConverter.convertHexToFloat("0xbf800000") == converterPair);

    converterPair.second = "-0.500000";
    REQUIRE(testConverter.convertHexToFloat("0xbf000000") == converterPair);

    converterPair.second = "0.000000";
    REQUIRE(testConverter.convertHexToFloat("0x00000000") == converterPair);

    converterPair.second = "0.500000";
    REQUIRE(testConverter.convertHexToFloat("0x3f000000") == converterPair);

    converterPair.second = "1.000000";
    REQUIRE(testConverter.convertHexToFloat("0x3f800000") == converterPair);

    converterPair.second = "1.500000";
    REQUIRE(testConverter.convertHexToFloat("0x3fc00000") == converterPair);
}

TEST_CASE( "Testing convert hex to float values with whitespaces in hex values", "[float-to-hex-whitespaces]" ) {
    ConverterData testConverter;

    auto converterPair = std::pair<ConverterStatus, std::string>{};
    /* Test cases with Status = OK and values from example */
    converterPair.first = ConverterStatus::OK;
    converterPair.second = "-1.500000";
    REQUIRE(testConverter.convertHexToFloat(" 0x bf c000 00") == converterPair);

    converterPair.second = "-1.000000";
    REQUIRE(testConverter.convertHexToFloat("0xbf  8000  00  ") == converterPair);

    converterPair.second = "-0.500000";
    REQUIRE(testConverter.convertHexToFloat("  0 x bf 000 0 00") == converterPair);

    converterPair.second = "0.000000";
    REQUIRE(testConverter.convertHexToFloat(" 0 x 0 0 0 0 0 0  0 0") == converterPair);

    converterPair.second = "0.500000";
    REQUIRE(testConverter.convertHexToFloat("               0x3f000000                ") == converterPair);

    converterPair.second = "1.000000";
    REQUIRE(testConverter.convertHexToFloat("0x 3f8    0  0 00  0") == converterPair);

    converterPair.second = "1.500000";
    REQUIRE(testConverter.convertHexToFloat("0 x 3fc00000") == converterPair);
}

TEST_CASE("convertHexToFloat with special input", "[convertHexToFloat-with-wrong-input-char ]" ) {
    ConverterData testConverter;

    auto converterPair = std::pair<ConverterStatus, std::string>{};

    converterPair.first = ConverterStatus::INVALID_ARGUMENT;
    converterPair.second = "NaN";
    REQUIRE(testConverter.convertHexToFloat("asd") == converterPair);

    converterPair.first = ConverterStatus::INVALID_ARGUMENT;
    converterPair.second = "NaN";
    REQUIRE(testConverter.convertHexToFloat("sample string with whitespaces") == converterPair);

    converterPair.first = ConverterStatus::OK;
    converterPair.second = "-1.000000";
    REQUIRE(testConverter.convertHexToFloat("0xbf 0x80 0x00 0x00") == converterPair);

    converterPair.first = ConverterStatus::OK;
    converterPair.second = "-0.500000";
    REQUIRE(testConverter.convertHexToFloat("0xbf0x000x000x00") == converterPair);

    converterPair.first = ConverterStatus::INVALID_ARGUMENT;
    converterPair.second = "NaN";
    REQUIRE(testConverter.convertHexToFloat("-1.5") == converterPair);

    converterPair.first = ConverterStatus::OK;
    converterPair.second = "-0.500000";
    REQUIRE(testConverter.convertHexToFloat("bf000000") == converterPair);

    converterPair.first = ConverterStatus::OUT_OF_RANGE;
    converterPair.second = "NaN";
    REQUIRE(testConverter.convertHexToFloat("0xFFFFFFFFFFFFFFFFFFF") == converterPair);
}

TEST_CASE("convertFloatToHex with special input", "[convertFloatToHex-with-wrong-input-char" ) {
    ConverterData testConverter;

    auto converter_pair = std::pair<ConverterStatus, std::string>{};

    converter_pair.first = ConverterStatus::OK;
    converter_pair.second = "0xbfc00000";
    REQUIRE(testConverter.convertFloatToHex("-1,5") == converter_pair);

    converter_pair.first = ConverterStatus::OK;
    converter_pair.second = "0x47f12010";
    REQUIRE(testConverter.convertFloatToHex("123456.123") == converter_pair);

    converter_pair.first = ConverterStatus::OK;
    converter_pair.second = "0x47f12010";
    REQUIRE(testConverter.convertFloatToHex("123.456,123") == converter_pair);

    converter_pair.first = ConverterStatus::INVALID_ARGUMENT;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex("-1.0.000.0.00,1213") == converter_pair);

    converter_pair.first = ConverterStatus::INVALID_ARGUMENT;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex(" -.0 ") == converter_pair);

    converter_pair.first = ConverterStatus::INVALID_ARGUMENT;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex("asd") == converter_pair);

    converter_pair.first = ConverterStatus::INVALID_ARGUMENT;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex("sample input string ") == converter_pair);

    converter_pair.first = ConverterStatus::OUT_OF_RANGE;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex("9999999999999999999999999999999999999999999999999999999.9") == converter_pair);

    converter_pair.first = ConverterStatus::OUT_OF_RANGE;
    converter_pair.second = "NaN";
    REQUIRE(testConverter.convertFloatToHex("-9999999999999999999999999999999999999999999999999999999.9") == converter_pair);
}