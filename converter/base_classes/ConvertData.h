#pragma once

/**
 * @file ConvertData.h
 * @brief The class that converts from 4 byte hex floats into a decimal float value or vice versa.
 */

#include <tuple>
#include <string>

/**
 * @enum ConverterStatus
 * @brief return values from methods
 */
enum class ConverterStatus {
    OK = 0,             /**< returned if no problems occur */
    INVALID_ARGUMENT,   /**< returned if the value to convert is not valid */
    OUT_OF_RANGE        /**< returned if the given value is higher then allowed */
};

/**
 * @class ConverterData
 * @brief Contains methods for converting float data and validating the data being converted
 */
class ConverterData {
public:
    ConverterData() = default;
    ~ConverterData() = default;

    /**
     * @brief converts decimal float data like -1.5 into a 4 byte hex value like 0xbfc00000, the value to convert and
     *      the converted value are strings
     * @param value the decimal string float value that will be converted into a 4 byte hex value
     * @return if the status is OK the 4 byte hex value will be returned
     */
    static std::pair<ConverterStatus, std::string> convertFloatToHex(const std::string &value);

    /**
     * @brief converts 4 byte float data like 0xbfc00000 into to a decimal float value like -1.5, the value to
     *      convert and the converted value are strings
     * @param value the 4 byte float value that will be converted into a decimal value
     * @return
     */
    static std::pair<ConverterStatus, std::string> convertHexToFloat(const std::string &value);

private:

    /**
     * @brief A method that calls all necessary methods to check whether the 4 byte hex values are OK
     * @param readVal the 4 byte float value to check
     * @return the converted value if all checks returned OK
     */
    static std::pair<ConverterStatus, std::string> checkHexReadString(std::string readVal);

    /**
     * @brief A method that calls all necessary methods to check whether the decimal value is OK
     * @param readVal the decimal float value to check
     * @return the converted value if all checks returned OK
     */
    static std::pair<ConverterStatus, std::string> checkFloatReadString(std::string readVal);

    /**
     * @brief removes spaces if present
     * @param readVal values passed for verification
     * @return the passed string without spaces
     */
    static std::pair<ConverterStatus, std::string> removeWhitespaces(const std::string &readVal);

    /**
     * @brief appends 0x to the beginning of the 4-byte floating point string if it doesn't exist
     * @param readVal the 4 byte hex value to check if it should start with an 0x
     * @return 4 byte hex value with 0x at start
     */
    static std::pair<ConverterStatus, std::string> checkHexStartChars(const std::string &readVal);

    /**
     * @brief checking for valid numbers and letters
     * @param readVal values passed for verification
     * @return OK if all numbers and letters are valid
     */
    static std::pair<ConverterStatus, std::string> checkHexValidValues(const std::string &readVal);

    /**
     * @brief replaces all commas with dots if present
     * @param readVal values passed for verification
     * @return values without commas
     */
    static std::pair<ConverterStatus, std::string> changeCommasToDots(const std::string &readVal);

    /**
     * @brief if there are multiple dots in the decimal float value, then all but the last one are removed
     * @param readVal values passed for verification
     * @return decimal float value with just one dot
     */
    static std::pair<ConverterStatus, std::string> determinateAllDotsExceptTheLastOne(const std::string &readVal);

    /**
     * @brief if a decimal floating point value starts with a dot or a -. then a 0 is added
     * @param readVal values passed for verification
     * @return decimal value with a 0 or -0 at start if necessary
     */
    static std::pair<ConverterStatus, std::string> addZeroIfFloatStartsWithDot(const std::string &readVal);

    /**
     * @brief checking for valid numbers and letters
     * @param readVal values passed for verification
     * @return OK if all numbers and letters are valid
     */
    static std::pair<ConverterStatus, std::string> checkDecimalValidValues(const std::string &readVal);

    /**
     * @brief Checks the number of digits, from a number of X the value is outside the permitted range
     * @param readVal values passed for verification
     * @return OK if all numbers and letters are valid
     */
    static std::pair<ConverterStatus, std::string> checkNumberOfDigits(const std::string &readVal);
};