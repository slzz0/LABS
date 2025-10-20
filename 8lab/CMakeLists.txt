cmake_minimum_required(VERSION 3.12)

project(lab8) 

include_directories(headers)

set(SOURCES
    src/main.cpp
    src/menu.cpp
    src/typeSelector.cpp
)

set(HEADERS
    include/algorithm.h
    include/exceptions.h
    include/menu.h
    include/node.h
    include/program.h
    include/ring.h
    include/typeSelector.h
    include/utils.h
)

add_executable(lab8 ${SOURCES} ${HEADERS})  
