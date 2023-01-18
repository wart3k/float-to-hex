#include "ConverterService.h"

#include <iostream>

ConverterService::~ConverterService() = default;

void ConverterService::startConverting() {

    std::cout << "Use float decimal values from: " << m_float_values_path << "\n";
    std::cout << "Use float hex values from: " << m_hex_values_path << "\n";
    std::cout << "Store converted values in: " << m_converted_values_path << "\n";
    std::cout << "\n";

    ConverterService::convertFloatDecimalToHex();
}

void ConverterService::convertFloatDecimalToHex() {
    std::cout << "Converting float to hex values status: \n";

    auto lineNrReadStatus = getMaxLineNr(m_float_values_path);

    if(lineNrReadStatus.first != ConverterReadStatus::OK) {
        std::cout << "Error while reading from: " << m_float_values_path << "\n";
        return;
    }

    std::cout << "Number of values to convert: " << lineNrReadStatus.second << "\n";

    auto lineReadValue = std::pair<ConverterReadStatus, std::string>{};
    auto converterValue = std::pair<ConverterStatus, std::string>{};
    for (size_t i = 0; i < lineNrReadStatus.second; ++i) {
        lineReadValue = readLine(m_float_values_path, i);

        auto readStatus = std::string{};
        switch(lineReadValue.first) {
            case ConverterReadStatus::OK:
                readStatus = "OK";
                break;
            case ConverterReadStatus::FILE_READING_ERROR:
                readStatus = "File read error";
                break;
            case ConverterReadStatus::SEARCHED_LINE_IS_HIGHER_THAN_MAX:
                readStatus = "Converted row is higher than max";
                break;
            case ConverterReadStatus::LENGTH_ERROR:
                readStatus = "length error";
                break;
            default:
                readStatus = "Undefined";
                break;
        }

        converterValue = convertFloatToHex(lineReadValue.second);

        std::cout << "Row nr: " << i << " read value: " << lineReadValue.second << " read status: " << readStatus
                  << " value is converted to: " << converterValue.second << "\n";

    }

}




