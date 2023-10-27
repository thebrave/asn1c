add_library(asn1print
asn1print.c asn1print.h
)

target_include_directories(asn1print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(asn1print PUBLIC
asn1common
asn1parser
asn1fix
)

