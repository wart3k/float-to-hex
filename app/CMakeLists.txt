set(EXECUTABLE_SOURCE
        "float_to_hex.cpp")

#set(EXECUTABLE_INCLUDE
#        "./")

add_executable(${EXECUTABLE_NAME}
        ${EXECUTABLE_SOURCE}
        )

target_include_directories(${EXECUTABLE_NAME} PUBLIC
        "${CMAKE_BINARY_DIR}/configured_files"
        )

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${READER_LIBRARY_NAME})