#include "ConverterService.h"

#include <iostream>

ConverterService::~ConverterService() = default;

void ConverterService::startConverting() {

    std::cout << "Use float decimal values from: " << m_float_values_path << "\n";
    std::cout << "Use float hex values from: " << m_hex_values_path << "\n";
    std::cout << "Store converted values in: " << m_converted_values_path << "\n";
    std::cout << "\n";

    ConverterService::convertFloatDecimalToHex();
    ConverterService::convertFloatHexToDecimal();
}

void ConverterService::convertFloatDecimalToHex() {
    std::cout << "Converting float to hex values status: \n";

    auto lineNrReadStatus = getMaxLineNr(m_float_values_path);

    if(lineNrReadStatus.first != ConverterReadStatus::OK) {
        std::cout << "\t -Error while reading from: " << m_float_values_path << "\n";
        return;
    }

    std::cout << "\t -Number of values to convert: " << lineNrReadStatus.second << "\n";

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

        if(static_cast<ConverterStatus>(lineReadValue.first) == ConverterStatus::OK) {
            converterValue = convertFloatToHex(lineReadValue.second);

            switch (converterValue.first) {
                case ConverterStatus::OK:
                    readStatus = "OK";
                    break;
                case ConverterStatus::INVALID_ARGUMENT:
                    readStatus = "Invalid Argument";
                    break;
                case ConverterStatus::OUT_OF_RANGE:
                    readStatus = "Out of Range";
                    break;
                default:
                    readStatus = "Unknown error";
                    break;
            }
        }
        std::cout << "\t -Row nr: " << i << " read value: " << lineReadValue.second << " read status: "
                  << readStatus << "\n";

        if(converterValue.first == ConverterStatus::OK) {
            std::cout << "\t\t - The value is converted to: " << converterValue.second << "\n";
        }


        auto writeStatus = writeValueAtEof(m_converted_values_path, converterValue.second + "\n");

        switch(writeStatus) {
            case ConverterWriteStatus::OK:
                readStatus = "OK";
                break;
            case ConverterWriteStatus::FILE_READING_ERROR:
                readStatus = "file reading error";
                break;
            default:
                readStatus = "Unknown error";
                break;
        }

        std::cout << "\t -Write value in file status: " << readStatus << "\n";

    }

    std::cout << "Converting float to hex done. \n\n";

}

void ConverterService::convertFloatHexToDecimal() {
    std::cout << "Converting hex to float values status: \n";
    std::cout << "\t method not implemented\n";
    std::cout << "Converting hex to float values done. \n";
}




