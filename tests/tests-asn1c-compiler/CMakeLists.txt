
if(BASH_EXECUTABLE)
    add_test(
        NAME check-parsing
        COMMAND bash -e check-parsing.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    SET_TESTS_PROPERTIES(check-parsing
        PROPERTIES
            ENVIRONMENT "top_srcdir=${PROJECT_SOURCE_DIR};top_builddir=${PROJECT_BINARY_DIR}")
endif()