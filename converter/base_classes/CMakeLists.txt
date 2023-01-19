set(DATA_RW_LIBRARY_SOURCES
        "ConverterReader.cpp"
        "ConverterWriter.cpp"
        "ConvertData.cpp")

set(DATA_RW_LIBRARY_INCLUDES
        "./")

add_library(${DATA_RW_LIBRARY_NAME} STATIC
        ${DATA_RW_LIBRARY_SOURCES})

target_include_directories(${DATA_RW_LIBRARY_NAME} PUBLIC
        ${DATA_RW_LIBRARY_INCLUDES})