#pragma once

/**
 * @file ConverterReader.h
 * @brief The class that is used to read text from a text file.
 */

#include <string>
#include <cstdint>
#include <tuple>

/**
 * @brief return values from methods
 */
enum class ConverterReadStatus {
    OK = 0,                             /**< returned if no problems occur */
    FILE_READING_ERROR,                 /**< returned if the file can't be read */
    SEARCHED_LINE_IS_HIGHER_THAN_MAX,   /**< returned if input is larger than file */
    LENGTH_ERROR                        /**< returned if the file is to large */
};


/**
 * @brief Contains methods to read from a text file
 */
class ConverterReader {
public:
    ConverterReader() = default;
    ~ConverterReader()  = default;

    /**
     * @brief read a specific line from a given text file
     *
     * @param path to the textfile
     * @param lineNr selected line to be read from the text file
     * @return the read status and the read line as a string, if the status is not OK then the string is empty
     */
    static std::pair<ConverterReadStatus, std::string> readLine(const std::string &path, std::uint32_t lineNr);

    /**
     * @brief reads the number of lines from a given text file
     *
     * @param path to the textfile
     * @return the read status and the number of lines, if the status is not OK then the number of
     *      lines is UINT32_MAX
     */
    static std::pair<ConverterReadStatus, std::uint32_t> getMaxLineNr(const std::string &path);
};