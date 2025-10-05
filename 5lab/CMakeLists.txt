cmake_minimum_required(VERSION 3.12)

project(lab5) 

include_directories(headers)

set(SOURCES
    src/main.cpp 
    src/menu.cpp
    src/program.cpp  
)

set(HEADERS
    include/program.h
    include/utils.h
    include/menu.h
)

add_executable(lab5 ${SOURCES} ${HEADERS})  
