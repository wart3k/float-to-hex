#pragma once

/**
 * @file ConverterWriter.h
 * @brief The class that is used to write text into a given file.
 */

#include <string>

/**
 * @enum ConverterWriteStatus
 * @brief return values from methods
 */
enum class ConverterWriteStatus {
    OK = 0,             /**< returned if no problems occur */
    FILE_READING_ERROR  /**< returned if writing is not possible */
};

/**
 * @class ConverterWriter
 * @brief Contains methods to write into a given text file
 */
class ConverterWriter {
public :
    ConverterWriter() = default;
    ~ConverterWriter() = default;

    /**
     * @brief writes a string into a specific line from a given text file
     * @param path to the file to write
     * @param textToWrite the string that will be write into the text
     * @return the write status
     */
    static ConverterWriteStatus writeValueAtEof(const std::string &path, const std::string &textToWrite);

};