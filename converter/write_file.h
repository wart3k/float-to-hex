#pragma once

#include <string>

class ConverterWriter {
public :
    ConverterWriter();
    ~ConverterWriter();

    void writeDate(const std::string &path);

};