add_executable(asn1c asn1c.c)
target_link_libraries(asn1c asn1parser asn1fix asn1print asn1compiler skeletons)

add_executable(enber enber.c)
target_link_libraries(enber asn1parser skeletons)

add_executable(unber unber.c)
target_link_libraries(unber asn1parser skeletons)
