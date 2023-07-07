#pragma once

#include <tuple>
#include <string>
#include <ConverterUtils.h>

class ConverterData {
public:
    ConverterData();
    ~ConverterData();

    static std::pair<ConverterStatus, std::string> convertFloatToHex(const std::string &value);
    static std::pair<ConverterStatus, std::string> convertHexToFloat(const std::string &value);

private:
    static std::pair<ConverterStatus, std::string> checkHexReadString(std::string readVal);
    static std::pair<ConverterStatus, std::string> checkFloatReadString(std::string readVal);

    static std::pair<ConverterStatus, std::string> removeWhitespaces(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> checkHexStartChars(const std::string &readVal);
    static std::pair<ConverterStatus, std::string> checkHexValidValues(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> changeCommasToDots(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> determAllDotsExceptTheLastOne(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> addZeroIfFloatStartsWithDot(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> checkValidValues(const std::string &readVal);

    static std::pair<ConverterStatus, std::string> checkNumberOfDigits(const std::string &readVal);
};