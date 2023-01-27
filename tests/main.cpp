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

TEST_CASE("Testing checkHexReadString", "[checkHexReadString]") {
    auto readMock = std::pair<ConverterStatus, std::string>{};
}