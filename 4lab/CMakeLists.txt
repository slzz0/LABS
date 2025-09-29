cmake_minimum_required(VERSION 3.12)

project(lab4) 

include_directories(headers)

set(SOURCES
    src/ancestor.cpp
    src/kid.cpp
    src/grandson.cpp
    src/program.cpp
    src/utils.cpp
    src/main.cpp 
    src/menu.cpp  
)

set(HEADERS
    include/ancestor.h
    include/kid.h
    include/grandson.h
    include/program.h
    include/utils.h
    include/menu.h
)

add_executable(lab4 ${SOURCES} ${HEADERS})  
