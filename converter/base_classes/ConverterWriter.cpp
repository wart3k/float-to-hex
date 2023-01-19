#include "ConverterWriter.h"

#include <fstream>

ConverterWriter::ConverterWriter() = default;

ConverterWriter::~ConverterWriter() = default;

ConverterWriteStatus ConverterWriter::writeValueAtEof(const std::string &path, const std::string &textToWrite) {
    auto offile = std::ofstream{};
    auto retVal = ConverterWriteStatus::OK;

    offile.open(path, std::ios::out | std::ios::app);

    if(offile.is_open()){
        offile << textToWrite;
    } else {
        retVal = ConverterWriteStatus::FILE_READING_ERROR;
    }

    offile.close();
    return retVal;
}
