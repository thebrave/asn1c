add_library(asn1fix
        asn1fix.c asn1fix.h
        asn1fix_internal.h
        asn1fix_misc.c asn1fix_misc.h
        asn1fix_value.c asn1fix_value.h
        asn1fix_compat.c asn1fix_compat.h
        asn1fix_constr.c asn1fix_constr.h
        asn1fix_cstring.c asn1fix_cstring.h
        asn1fix_retrieve.c asn1fix_retrieve.h
        asn1fix_bitstring.c asn1fix_bitstring.h
        asn1fix_constraint.c asn1fix_constraint.h
        asn1fix_integer.c asn1fix_integer.h
        asn1fix_crange.c asn1fix_crange.h
        asn1fix_dereft.c asn1fix_dereft.h
        asn1fix_derefv.c asn1fix_derefv.h
        asn1fix_export.c asn1fix_export.h
        asn1fix_param.c asn1fix_param.h
        asn1fix_class.c asn1fix_class.h
        asn1fix_tags.c asn1fix_tags.h
        asn1fix_enum.c asn1fix_enum.h
        asn1fix_cws.c asn1fix_cws.h
        asn1fix_constraint_compat.c
)

target_include_directories(asn1fix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(asn1fix PUBLIC
        asn1common
        asn1parser
)

add_executable(check_crange asn1fix_crange.c asn1fix_constraint_compat.c)
target_compile_definitions(check_crange PRIVATE UNIT_TEST)
target_link_libraries(check_crange PUBLIC asn1fix)
add_test(NAME check_crange COMMAND check_crange)

add_executable(check_fixer check_fixer.c)
target_link_libraries(check_fixer PUBLIC asn1fix)
add_test(NAME check_fixer COMMAND check_fixer)

SET_TESTS_PROPERTIES(check_fixer
        PROPERTIES ENVIRONMENT "TOP_SRCDIR=${PROJECT_SOURCE_DIR}")