#include <iostream>
#include <string>

#include "config.h"
//#include "read_file.h"
//#include "write_file.h"
#include "converter.h"

int main() {
    std::cout << "Starting project: " << project_name << " Version: " << project_version << "\n";

//    ConverterReader ConverterReader;
//    ConverterWriter ConverterWriter;
    Converter Converter;

//    auto readerTest = ConverterReader::getMaxLineNr("../../converter_files/float_hex.txt");
//
//    if(readerTest.first == ConverterReadStatus::OK) {
//        for (std::uint32_t i = 0; i < readerTest.second; ++i) {
//            auto readerTest2 = ConverterReader::readLine("../../converter_files/float_hex.txt", i);
//            if(readerTest2.first == ConverterReadStatus::OK)
//                std::cout << "Value is: " << readerTest2.second << "\n";
//        }
//    }
//
//
//
//    ConverterWriter::writeValueAtEof("../../converter_files/converted.txt", "test\n");

    Converter::convertFloatToHex("-0.5");

    return EXIT_SUCCESS;
}
