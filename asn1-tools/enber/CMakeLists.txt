add_executable(enber enber.c)

target_link_libraries(enber PUBLIC
        asn1common
        asn1parser
        asn1cskeletons
)

if (WIN32)
    target_link_libraries(enber PUBLIC getopt)
endif ()

target_compile_definitions(enber PRIVATE VERSION="${SW_VERSION}")
