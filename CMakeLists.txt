cmake_minimum_required(VERSION 3.24)

project(
        float_to_hex
        VERSION 0.1.0
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

set(EXECUTABLE_NAME float_to_hex)
set(READER_LIBRARY_NAME reader_libraries)

add_subdirectory(configured)
add_subdirectory(app)
add_subdirectory(converter)
