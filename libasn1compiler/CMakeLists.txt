add_library(asn1compiler
        asn1compiler.c asn1compiler.h
        asn1c_misc.c asn1c_misc.h
        asn1c_out.c asn1c_out.h
        asn1c_lang.c asn1c_lang.h
        asn1c_naming.c asn1c_naming.h
        asn1c_save.c asn1c_save.h
        asn1c_C.c asn1c_C.h
        asn1c_constraint.c asn1c_constraint.h
        asn1c_compat.c asn1c_compat.h
        asn1c_ioc.c asn1c_ioc.h
        asn1c_fdeps.c asn1c_fdeps.h
        asn1c_internal.h
)

target_include_directories(asn1compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(asn1compiler PUBLIC
        asn1common
        asn1parser
        asn1print
        asn1fix)