#include "ConverterWriter.h"

#include <fstream>

ConverterWriteStatus ConverterWriter::writeValueAtEof(const std::string &path, const std::string &textToWrite) {
    auto offile = std::ofstream{};
    auto retVal = ConverterWriteStatus::FILE_READING_ERROR;

    offile.open(path, std::ios::out | std::ios::app);

    if(offile.is_open()){
        offile << textToWrite;
        retVal = ConverterWriteStatus::OK;
    }

    offile.close();
    return retVal;
}
