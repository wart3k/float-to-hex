#pragma once

#include <string>

enum class ConverterWriteStatus {
    OK = 0,
    FILE_READING_ERROR
};

class ConverterWriter {
public :
    ConverterWriter();
    ~ConverterWriter();

    static ConverterWriteStatus writeValueAtEof(const std::string &path, const std::string &textToWrite);

};