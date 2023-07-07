/**
 * @file   floatToHex.cpp
 * @Author WART3K
 * @date   July, 2023
 * @brief  The main file for this project
 *
 * This is the main file. First it prints the path's and then it generates an object from the Converter Service.
 * This Service has the possibility to read convert and write. The Order is:
 * 1: Read value
 * 2: Convert
 * 3: Write value
 */

#include <iostream>
#include <string>

#include "config.h"
#include "ConverterService.h"

int main() {
    std::cout << "Starting project: " << project_name << " Version: " << project_version << "\n";

    auto pathToFloatValues = std::string{"../../converter_files/float_dec.txt"};
    auto pathToHexValues = std::string{"../../converter_files/float_hex.txt"};
    auto pathToConvertedValues = std::string{"../../converter_files/converted.txt"};

    ConverterService ConverterController(pathToFloatValues, pathToHexValues,
                                         pathToConvertedValues);

    ConverterController.startConverting();

    return EXIT_SUCCESS;
}
