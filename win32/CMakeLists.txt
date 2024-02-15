add_library(win32support
    win32support.c
    win32support.h
)

target_include_directories(win32support SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(getopt
    getopt.c
    getopt.h
)

target_include_directories(getopt SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(HAVE_STRING_H)
    target_compile_definitions(getopt PRIVATE HAVE_STRING_H)
endif ()