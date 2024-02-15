cmake_minimum_required(VERSION 3.16)

project(asn1c)

enable_language(C)
enable_testing()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_EXTENSIONS ON)
else ()
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_EXTENSIONS ON)
endif ()

set(SW_VERSION "0.9.29")

find_program(BASH_EXECUTABLE bash)

find_package(Perl REQUIRED)

option(ASN_DEBUG "produce debug log during `make check` testing" OFF)

set(ASN_DATADIR skeletons)

add_compile_definitions(HAVE_CONFIG_H)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

include(CheckSymbolExists)
set(CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
check_symbol_exists(vasprintf "stdio.h" HAVE_DECL_VASPRINTF)
check_symbol_exists(isatty "unistd.h" HAVE_DECL_ISATTY)

include(CheckIncludeFile)
CHECK_INCLUDE_FILE(sys/stat.h HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILE(sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE(unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILE(string.h HAVE_STRING_H)
CHECK_INCLUDE_FILE(inttypes.h HAVE_INTTYPES_H)

configure_file(config.h.template ${PROJECT_BINARY_DIR}/config/config.h)
include_directories(${PROJECT_BINARY_DIR}/config)

add_subdirectory(libasn1common)
add_subdirectory(libasn1compiler)
add_subdirectory(libasn1fix)
add_subdirectory(libasn1parser)
add_subdirectory(libasn1print)

add_subdirectory(asn1c)
add_subdirectory(asn1-tools)
add_subdirectory(tests)
add_subdirectory(skeletons)

if(WIN32)
    add_subdirectory(win32)
endif()