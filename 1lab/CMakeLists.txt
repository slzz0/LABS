cmake_minimum_required(VERSION 3.12)

project(lab1)


include_directories(headers)

set(SOURCES
    source/main.cpp
    source/matrix.cpp
    source/menu.cpp
    source/program.cpp
    source/utilits.cpp
)

set(HEADERS
    headers/matrix.h
    headers/menu.h
    headers/program.h
    headers/utilits.h
)

add_executable(lab1 ${SOURCES} ${HEADERS})
