#pragma once

/**
 * @file ConverterService.h
 * @brief The class that reads converts and writes the given data
 */

#include <string>

#include "ConverterReader.h"
#include "ConverterWriter.h"
#include "ConvertData.h"

/**
 * @class ConverterService
 * @brief Contains methods to read, convert and write
 */
class ConverterService : public ConverterReader, public ConverterData, public ConverterWriter{

public:
    /**
     * @brief constructor that sets the path's to the read and write files
     * @param floatValPath path to the decimal float values
     * @param hexValPath path to the 4 byte hex float values
     * @param convertedValsPath path to the file where the converted files will be stored
     */
    ConverterService(std::string &floatValPath, std::string &hexValPath,
                     std::string &convertedValsPath)
                     : m_float_values_path(floatValPath), m_hex_values_path(hexValPath),
                     m_converted_values_path(convertedValsPath){};

    /**
     * @brief default deconstructor
     */
    ~ConverterService() = default;

    /**
     * @brief this method starts to read from a given file, if the values in the file are valid the next step is the
     *      value will be converted, if the conversion is ok the converted file will be written in an extra file
     */
    void startConverting();

private:

    /**
     * @enum ConvertType
     * @brief used to choose the converting type
     */
    enum class ConvertType {
        HEX_TO_FLOAT,   /**< used to convert from 4 byte float hex values to decimal values */
        FLOAT_TO_HEX    /**< used to convert from decimal float values to 4 byte float hex values */
    };

    /**
     * @brief writes the header in the textfile
     * @param type with the type the text will be chose
     */
    void writeHeaderToConvertedFile(ConvertType type);

    /**
     * @brief reads the data from a file, then tries to convert it and write it in a separate file
     * @param type the converting type
     */
    void readConvertWriteValues(ConvertType type);

    const std::string m_float_values_path;      /**< path to the decimal float values */
    const std::string m_hex_values_path;        /**< path to the 4 byte hex float values */
    const std::string m_converted_values_path;  /**< path to the file where the converted values will be written */
};
