#include "ConverterService.h"

#include <iostream>

void ConverterService::startConverting() {

    std::cout << "Use float decimal values from: " << m_float_values_path << "\n";
    std::cout << "Use float hex values from: " << m_hex_values_path << "\n";
    std::cout << "Store converted values in: " << m_converted_values_path << "\n";
    std::cout << "\n";

    ConverterService::writeHeaderToConvertedFile(ConvertType::FLOAT_TO_HEX);
    ConverterService::readConvertWriteValues(ConvertType::FLOAT_TO_HEX);

    ConverterService::writeHeaderToConvertedFile(ConvertType::HEX_TO_FLOAT);
    ConverterService::readConvertWriteValues(ConvertType::HEX_TO_FLOAT);
}

void ConverterService::writeHeaderToConvertedFile(ConvertType type) {
    auto stringToWrite = std::string{};

    switch (type) {
        case ConvertType::FLOAT_TO_HEX:
            stringToWrite = "\nConverted float values into hex values\n";
            break;
        case ConvertType::HEX_TO_FLOAT:
            stringToWrite = "\nConverted hex values into float values\n";
            break;
        default:
            stringToWrite = "\nConvertion type doesn't exists\n";
            break;
    }

    stringToWrite += "----------------------------------------------------\n";

    auto writeStatus = writeValueAtEof(m_converted_values_path, stringToWrite);

    if (writeStatus != ConverterWriteStatus::OK) {
        std::cout << "Writing error\n";
    }
}


void ConverterService::readConvertWriteValues(ConvertType type) {

    auto pathToValues = std::string{};

    if(type == ConvertType::FLOAT_TO_HEX) {
        std::cout << "Converting float to hex values status: \n";
        pathToValues = m_float_values_path;
    } else {
        std::cout << "Converting hex to float values status: \n";
        pathToValues = m_hex_values_path;
    }

    auto lineNrReadStatus = getMaxLineNr(pathToValues);

    if(lineNrReadStatus.first != ConverterReadStatus::OK) {
        std::cout << "\t -Error while reading from: " << pathToValues << "\n";
        return;
    }

    std::cout << "\t -Number of values to convert: " << lineNrReadStatus.second << "\n";

    auto lineReadValue = std::pair<ConverterReadStatus, std::string>{};
    auto converterValue = std::pair<ConverterStatus, std::string>{};
    for (size_t i = 0; i < lineNrReadStatus.second; ++i) {
        lineReadValue = readLine(pathToValues, i);

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
            if(type == ConvertType::FLOAT_TO_HEX) {
                converterValue = convertFloatToHex(lineReadValue.second);
            } else {
                converterValue = convertHexToFloat(lineReadValue.second);
            }

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

    if(type == ConvertType::FLOAT_TO_HEX) {
        std::cout << "Converting float to hex done. \n\n";
    } else {
        std::cout << "Converting hex to float done. \n\n";
    }

}



