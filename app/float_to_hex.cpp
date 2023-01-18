#include <iostream>
#include <string>

#include "config.h"
#include "ConverterService.h"

int main() {
    std::cout << "Starting project: " << project_name << " Version: " << project_version << "\n";

    ConverterService ConverterController;
    ConverterController.startConverting();

    return EXIT_SUCCESS;
}
