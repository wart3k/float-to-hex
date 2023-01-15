set(DATA_RW_LIBRARY_SOURCES
        "read_file.cpp"
        "write_file.cpp")

set(DATA_RW_LIBRARY_INCLUDES
        "./")

add_library(${DATA_RW_LIBRARY_NAME} STATIC
        ${DATA_RW_LIBRARY_SOURCES})

target_include_directories(${DATA_RW_LIBRARY_NAME} PUBLIC
        ${DATA_RW_LIBRARY_INCLUDES})