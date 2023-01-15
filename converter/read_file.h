#pragma once

#include <string>
#include <cstdint>

class ConverterReader {
public:
    ConverterReader();
    ~ConverterReader();

    static void readValue(const std::string& path);
};