#pragma once

#include <string>

#include "read_file.h"
#include "write_file.h"
#include "convert_data.h"

class ConverterService : public ConverterReader, public Converter, public ConverterWriter{

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
