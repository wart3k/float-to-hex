#pragma once

#include <string>
#include <cstdint>
#include <tuple>

enum class ConverterReadStatus {
    OK = 0,
    FILE_READING_ERROR,
    SEARCHED_LINE_IS_HIGHER_THAN_MAX,
    LENGTH_ERROR
};

class ConverterReader {
public:
    ConverterReader();
    ~ConverterReader();

    static std::pair<ConverterReadStatus, std::string> readLine(const std::string &path, std::uint32_t lineNr);
    static std::pair<ConverterReadStatus, std::uint32_t> getMaxLineNr(const std::string &path);
};