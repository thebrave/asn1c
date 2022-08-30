add_library(asn1print
    asn1print.c asn1print.h
)

target_include_directories(asn1print INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(asn1print asn1parser asn1fix)
