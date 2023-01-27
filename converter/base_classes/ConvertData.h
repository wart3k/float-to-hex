#pragma once

#include <tuple>
#include <string>

enum class ConverterStatus {
    OK = 0,
    INVALID_ARGUMENT,
    OUT_OF_RANGE
};

class ConverterData {
public:
    ConverterData();
    ~ConverterData();

    static std::pair<ConverterStatus, std::string> convertFloatToHex(const std::string &value);
    static std::pair<ConverterStatus, std::string> convertHexToFloat(const std::string &value);

private:
    static std::pair<ConverterStatus, std::string> checkHexReadString(std::string readVal);
    static std::pair<ConverterStatus, std::string> checkFloatReadString(std::string readVal);

    static std::pair<ConverterStatus, std::string> removeWhitespaces(const std::string&);

};