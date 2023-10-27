add_executable(asn1c asn1c.c)

target_link_libraries(asn1c PUBLIC
        asn1common
        asn1parser
        asn1print
        asn1fix
        asn1compiler
)

if (WIN32)
    target_link_libraries(asn1c PUBLIC getopt)
endif ()

target_compile_definitions(asn1c PRIVATE DATADIR="${ASN_DATADIR}")