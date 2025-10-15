cmake_minimum_required(VERSION 3.12)

project(lab7) 

include_directories(headers)

set(SOURCES
    src/date.cpp
    src/main.cpp
    src/menu.cpp
    src/product.cpp
    src/program.cpp
    src/utils.cpp
)

set(HEADERS
    include/date.h
    include/consts.h
    include/menu.h
    include/product.h
    include/program.h
    include/utils.h
)

add_executable(lab7 ${SOURCES} ${HEADERS})  
