cmake_minimum_required(VERSION 3.12)

project(lab3) 

include_directories(headers)

set(SOURCES
    src/bicycle.cpp
    src/car.cpp
    src/carriage.cpp
    src/menu.cpp
    src/program.cpp
    src/transport.cpp
    src/utils.cpp
    src/main.cpp  
)

set(HEADERS
    include/bicycle.h
    include/car.h
    include/carriage.h
    include/consts.h
    include/menu.h
    include/program.h
    include/transport.h
    include/utils.h
)

add_executable(lab3 ${SOURCES} ${HEADERS})  
