#include <iostream>

#include "config.h"
#include "read_file.h"

int main() {
    std::cout << "Starting project: " << project_name << " Version: " << project_version << "\n";

    ConverterReader ConverterReader;

    ConverterReader::readValue("../../converter_files/float_dec.txt");

    return EXIT_SUCCESS;
}
