#include "ConverterService.h"

#include <iostream>

//#include "read_file.h"
//#include "write_file.h"
//#include "convert_data.h"

ConverterService::ConverterService() = default;

ConverterService::~ConverterService() = default;

void ConverterService::startConverting(void) {
    std::cout << "Start Converting\n";

//    ConverterReader ConverterReader;
//    ConverterWriter ConverterWriter;
//    Converter Converter;
//
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
//
//    Converter::convertFloatToHex("-1.5");
//    Converter::convertHexToFloat("0xbfc00000");
}
