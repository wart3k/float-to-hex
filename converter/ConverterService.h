#pragma once

#include <string>

#include "ConverterReader.h"
#include "ConverterWriter.h"
#include "ConvertData.h"

class ConverterService : public ConverterReader, public ConverterData, public ConverterWriter{

public:
    ConverterService(std::string &floatValPath, std::string &hexValPath,
                     std::string &convertedValsPath)
                     : m_float_values_path(floatValPath), m_hex_values_path(hexValPath),
                     m_converted_values_path(convertedValsPath){};
    ~ConverterService();

    void startConverting();

private:
    enum class ConvertType {
        HEX_TO_FLOAT,
        FLOAT_TO_HEX
    };

    void writeHeaderToConvertedFile(ConvertType type);
    void readConvertWriteValues(ConvertType type);

    const std::string m_float_values_path;
    const std::string m_hex_values_path;
    const std::string m_converted_values_path;
};
