set(test_list "check-GeneralizedTime;check-INTEGER;check-OCTET_STRING;check-OER-INTEGER;check-OER-NativeEnumerated;check-OER-support;check-OIDs;check-PER-INTEGER;check-PER-UniversalString;check-PER-support;check-REAL;check-UTCTime;check-UTF8String;check-XER;check-ber_tlv_tag;check-bits;check-length")

foreach (loopVAR IN LISTS test_list)
    # message("Source from a SOURCES: ${loopVAR}")
    add_executable(${loopVAR} ${loopVAR}.c)
    target_link_libraries(${loopVAR} asn1cskeletons)
    add_test(NAME ${loopVAR} COMMAND ${loopVAR})

    if (WIN32)
        target_include_directories(${loopVAR} SYSTEM PRIVATE ${PROJECT_SOURCE_DIR}/win32)
    endif ()
endforeach ()
