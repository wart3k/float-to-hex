set(READER_LIBRARY_SOURCES
        "read_file.cpp")

set(READER_LIBRARY_INCLUDES
        "./")

add_library(${READER_LIBRARY_NAME} STATIC
        ${READER_LIBRARY_SOURCES})

target_include_directories(${READER_LIBRARY_NAME} PUBLIC
        ${READER_LIBRARY_INCLUDES})