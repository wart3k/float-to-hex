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
