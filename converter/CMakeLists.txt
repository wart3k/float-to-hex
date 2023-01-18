set(CONVERTER_LIBRARY_SOURCES
        "ConverterService.cpp")

set(CONVERTER_LIBRARY_INCLUDES
        "./")

add_library(${CONVERTER_LIBRARY_NAME} STATIC
        ${CONVERTER_LIBRARY_SOURCES})

add_subdirectory(base_classes)

target_include_directories(${CONVERTER_LIBRARY_NAME} PUBLIC
        ${CONVERTER_LIBRARY_INCLUDES})

target_link_libraries(${CONVERTER_LIBRARY_NAME} PUBLIC ${DATA_RW_LIBRARY_NAME})