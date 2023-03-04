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

std::pair<ConverterStatus, std::string> ConverterData::convertFloatToHex(const std::string &value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};

    retVal = ConverterData::checkFloatReadString(value);

    if (retVal.first == ConverterStatus::OK) {
        try {
            auto convertVal = floatConv{ .i = UINT32_MAX };
            auto stringStr = std::stringstream();

            convertVal.f = std::stof(retVal.second);

            if (convertVal.i == 0) {
                stringStr << "0x00000000";
            } else {
                stringStr << "0x" << std::hex << convertVal.i;
            }

            retVal.second = stringStr.str();

        } catch (std::invalid_argument const &e) {
            retVal.first = ConverterStatus::INVALID_ARGUMENT;
        } catch (std::out_of_range const &e) {
            retVal.first = ConverterStatus::OUT_OF_RANGE;
        }
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::convertHexToFloat(const std::string &value) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};

    auto convertVal = floatConv { .i = UINT32_MAX };
    auto stringStr = std::stringstream();
    char *p_end{};

    retVal = ConverterData::checkHexReadString(value);
    if(retVal.first != ConverterStatus::OK) {
        retVal.second = "nan";
        return retVal;
    }

    convertVal.i = strtoul(retVal.second.c_str(), &p_end, 16);

    if(retVal.second.c_str() == p_end) {
        std::cout << "FLOAT_TO_HEX ERROR: invalid argument, error \n";
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
        retVal.second = "nan";
        return retVal;
    }

    const bool range_error = errno == ERANGE;
    const std::string extracted(retVal.second.c_str(), p_end - retVal.second.c_str());

    if (range_error || retVal.second.size() > 10) {
        std::cout << "FLOAT_TO_HEX ERROR: out of range, error \n";
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        retVal.second = "nan";
        return retVal;
    }

    retVal.second = std::to_string(convertVal.f);

    if(retVal.second == "nan") {
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        retVal.second = "inf";
    } else if(retVal.second == "-nan") {
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        retVal.second = "-inf";
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkHexReadString(std::string readVal) {

    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::INVALID_ARGUMENT, "nan"};

    retVal.second = std::move(readVal);

    retVal = ConverterData::removeWhitespaces(retVal.second);
    if(retVal.first != ConverterStatus::OK) {
        return retVal;
    }

    retVal = ConverterData::checkHexStartChars(retVal.second);
    if(retVal.first != ConverterStatus::OK) {
        return retVal;
    }

    retVal = ConverterData::checkHexValidValues(retVal.second);
    if(retVal.first != ConverterStatus::OK) {
        return retVal;
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkFloatReadString(std::string readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};

    retVal.second = std::move(readVal);

    retVal = ConverterData::removeWhitespaces(retVal.second);

    retVal = ConverterData::changeCommasToDots(retVal.second);

    retVal = ConverterData::determinateAllDotsExceptTheLastOne(retVal.second);

    retVal = ConverterData::addZeroIfFloatStartsWithDot(retVal.second);

    retVal = ConverterData::checkDecimalValidValues(retVal.second);
    if(retVal.first != ConverterStatus::OK)
        return retVal;

    retVal = checkNumberOfDigits(retVal.second);

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkHexStartChars(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, readVal};

    if(retVal.second.starts_with("x")) {
        retVal.second = "0" + retVal.second;
    } else if(!retVal.second.starts_with("0x")) {
        retVal.second = "0x" + retVal.second;
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkHexValidValues(const std::string &readVal) {

    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};

    retVal.second = readVal;

    //check number of chars
    if(retVal.second.size() < 10) {
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
        return retVal;
    }

    //Check unnecessary 0x values
    for(size_t i = 2; i < retVal.second.size(); ++i) {
        if(((retVal.second[i] == 'x') || (retVal.second[i] == 'X') &&
        retVal.second[i-1] == '0')) {
            retVal.second.erase(i-1, 2);
        }
    }

    //Check every single char
    for(size_t i = 2; i < retVal.second.size(); ++i) {
        if(retVal.second[i] != '0' &&
        retVal.second[i] != '1' &&
        retVal.second[i] != '2' &&
        retVal.second[i] != '3' &&
        retVal.second[i] != '4' &&
        retVal.second[i] != '5' &&
        retVal.second[i] != '6' &&
        retVal.second[i] != '7' &&
        retVal.second[i] != '8' &&
        retVal.second[i] != '9' &&
        retVal.second[i] != 'A' &&
        retVal.second[i] != 'B' &&
        retVal.second[i] != 'C' &&
        retVal.second[i] != 'D' &&
        retVal.second[i] != 'E' &&
        retVal.second[i] != 'F' &&
        retVal.second[i] != 'a' &&
        retVal.second[i] != 'b' &&
        retVal.second[i] != 'c' &&
        retVal.second[i] != 'd' &&
        retVal.second[i] != 'e' &&
        retVal.second[i] != 'f') {
            retVal.first = ConverterStatus::INVALID_ARGUMENT;
            return retVal;
        }
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::removeWhitespaces(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    try {
        retVal.second.erase(std::remove(retVal.second.begin(), retVal.second.end(), ' '),
                            retVal.second.end());

    } catch (std::invalid_argument const &e) {
        retVal.first = ConverterStatus::INVALID_ARGUMENT;
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::changeCommasToDots(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    for(char &i : retVal.second) {
        if(i == ',')
            i = '.';
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::determinateAllDotsExceptTheLastOne(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    auto numberOfDots = std::uint8_t{0};

    for(char &i : retVal.second) {
        if(i == '.')
            ++numberOfDots;
    }

    if(numberOfDots == 0) {
        retVal.second = retVal.second + ".0";
    } else if(numberOfDots == 1) {
        return retVal;
    } else {

        for(auto i = 0; i < retVal.second.size(); i++) {

            if (retVal.second[i] == '.' && numberOfDots > 1) {
                retVal.second.erase(retVal.second.begin() + i, retVal.second.begin() + i + 1);
                --numberOfDots;
            }

        }

    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::addZeroIfFloatStartsWithDot(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    if (retVal.second[0] == '.'){
        retVal.second = retVal.second.insert(0, "0");
    } else if (retVal.second[0] == '-' && retVal.second[1] == '.'){
        retVal.second = retVal.second.insert(1, "0");
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkDecimalValidValues(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    for(auto i : retVal.second) {
        if(i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6' && i != '7' && i != '8' &&
        i != '9' && i != '.' && i != '-' && i != '+' && i != 'e' && i != 'E'){
            retVal.first = ConverterStatus::INVALID_ARGUMENT;
            retVal.second = "nan";
            return retVal;
        }
    }

    return retVal;
}

std::pair<ConverterStatus, std::string> ConverterData::checkNumberOfDigits(const std::string &readVal) {
    auto retVal = std::pair<ConverterStatus, std::string>{ConverterStatus::OK, "nan"};
    retVal.second = readVal;

    if(retVal.second.size() > 30) {
        retVal.first = ConverterStatus::OUT_OF_RANGE;
        retVal.second = "nan";
    }

    return retVal;
}
