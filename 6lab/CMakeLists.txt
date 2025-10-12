cmake_minimum_required(VERSION 3.20)

project(lab6) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
    src/invalidException.cpp
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
    include/invalidException.h
)

add_executable(lab6 ${SOURCES} ${HEADERS})  
