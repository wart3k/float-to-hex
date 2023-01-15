#include "write_file.h"

#include <fstream>

ConverterWriter::ConverterWriter() = default;

ConverterWriter::~ConverterWriter() = default;

void ConverterWriter::writeDate(const std::string &path) {
    auto offile = std::ofstream{};

    auto testText = std::string{"test\n"};

    offile.open(path);

    if(offile.is_open()){
        offile << testText;
    }

    offile.close();
}
