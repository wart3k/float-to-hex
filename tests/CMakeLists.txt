if(ENABLE_TESTING)

    set(TESTS_MAIN "unit_tests")

    set(TESTS_SOURCES
            "main.cpp")

#    set(TESTS_INCLUDES
#            "./")

    add_executable(${TESTS_MAIN}
            ${TESTS_SOURCES}
            )


#    target_include_directories(${TESTS_MAIN} PUBLIC
#            ${TESTS_INCLUDES})

    target_link_libraries(${TESTS_MAIN} PRIVATE
            ${DATA_RW_LIBRARY_NAME}
            ${CONVERTER_LIBRARY_NAME}
            Catch2::Catch2)

endif()