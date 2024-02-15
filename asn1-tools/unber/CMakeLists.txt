add_executable(unber unber.c)

target_link_libraries(unber PUBLIC
        asn1_unber_tool
)

if (WIN32)
    target_link_libraries(unber PUBLIC getopt)
endif ()

target_compile_definitions(unber PRIVATE VERSION="${SW_VERSION}")

add_executable(check_unber check_unber.c)

target_link_libraries(check_unber PUBLIC
        asn1_unber_tool
)

if (WIN32)
    target_link_libraries(check_unber PUBLIC getopt)
endif ()

add_test(NAME check_unber COMMAND check_unber)

add_library(asn1_unber_tool
libasn1_unber_tool.c libasn1_unber_tool.h
)
target_link_libraries(asn1_unber_tool PUBLIC
        asn1parser
        asn1common
        asn1cskeletons
)