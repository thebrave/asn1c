add_library(asn1common
        asn1_common.h asn1_ref.c asn1_ref.h
        asn1_buffer.c asn1_buffer.h
        asn1_namespace.c asn1_namespace.h
        genhash.c genhash.h
)
target_include_directories(asn1common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})