#include <iostream>
#include <string>

#include "config.h"
#include "ConverterService.h"

#include "FloatToHexConverter.h"

int main() {
    std::cout << "Starting project: " << project_name << " Version: " << project_version << "\n";

//    auto pathToFloatValues = std::string{"../../converter_files/float_dec.txt"};
//    auto pathToHexValues = std::string{"../../converter_files/float_hex.txt"};
//    auto pathToConvertedValues = std::string{"../../converter_files/converted.txt"};
//
//    ConverterService ConverterController(pathToFloatValues, pathToHexValues,
//                                         pathToConvertedValues);
//    ConverterController.startConverting();

    auto test = FloatToHexConverter();
    test.getHexFromFloat(346346346346343463463464.0);

    return EXIT_SUCCESS;
}
