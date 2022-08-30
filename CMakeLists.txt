cmake_minimum_required(VERSION 3.10)

# set the project name
project(asn1c)

include(GNUInstallDirs)
add_compile_definitions(DATADIR="${CMAKE_INSTALL_FULL_DATAROOTDIR}/")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

include(CheckIncludeFile)
CHECK_INCLUDE_FILE("inttypes.h" CMAKE_HAVE_INTTYPES_H)
CHECK_INCLUDE_FILE("stdint.h" CMAKE_HAVE_STDINT_H)
CHECK_INCLUDE_FILE("sys/param.h" CMAKE_HAVE_SYS_PARAM_H)
CHECK_INCLUDE_FILE("sys/stat.h" CMAKE_HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILE("sys/types.h" CMAKE_HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE("unistd.h" CMAKE_HAVE_UNISTD_H)

if(${CMAKE_HAVE_SYS_STAT_H})
    add_compile_definitions(HAVE_SYS_STAT_H)
endif()

if(${CMAKE_HAVE_UNISTD_H})
    add_compile_definitions(HAVE_UNISTD_H)
endif()

if(${CMAKE_HAVE_SYS_PARAM_H})
    add_compile_definitions(HAVE_SYS_PARAM_H)
endif()

if(${CMAKE_HAVE_STDINT_H})
    add_compile_definitions(HAVE_STDINT_H)
endif()

if(${CMAKE_HAVE_SYS_TYPES_H})
    add_compile_definitions(HAVE_SYS_TYPES_H)
endif()

if(${CMAKE_HAVE_INTTYPES_H})
    add_compile_definitions(HAVE_INTTYPES_H)
endif()

add_compile_definitions(_DEFAULT_SOURCE)

include(describe-git-version.cmake)
git_describe_directory(GIT_VERSION ${PROJECT_SOURCE_DIR})

add_compile_definitions(VERSION="${GIT_VERSION}")

# add the executable
add_subdirectory(asn1c)
add_subdirectory(libasn1compiler)
add_subdirectory(libasn1fix)
add_subdirectory(libasn1parser)
add_subdirectory(libasn1print)
add_subdirectory(skeletons)
