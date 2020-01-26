cmake_minimum_required(VERSION 3.10)

#set project name and number
project(GameOfLife VERSION 1.5)

#set C++ version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Bring the headers into project
include_directories(includes)

#manually add sources or GLOB
#set(SOURCES src/gol.cpp src/run.cpp)

#GLOB
file(GLOB SOURCES "src/*.cpp")
file(GLOB INPUT "input/*.txt")

# add the executable
add_executable(GameOfLife ${SOURCES})

#add file to configure version
#configure_file(GolConfig.h.in GolConfig.h)

#add input file
configure_file(${INPUT}
               ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#set cmake build type
set(CMAKE_BUILD_TYPE Debug)