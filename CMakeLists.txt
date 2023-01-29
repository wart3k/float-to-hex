cmake_minimum_required(VERSION 3.24)

project(
        float-to-hex
        VERSION 0.1.2
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

option(ENABLE_TESTING "Enable Unit Test Build"      ON)

set(EXECUTABLE_NAME float-to-hex)
set(DATA_RW_LIBRARY_NAME reader_libraries)
set(CONVERTER_LIBRARY_NAME converter_libraries)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v2.13.10
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(configured)
add_subdirectory(converter)
add_subdirectory(app)
add_subdirectory(tests)