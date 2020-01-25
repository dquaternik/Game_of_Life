cmake_minimum_required(VERSION 3.10)

#set project name and number
project(GameOfLife VERSION 1.0)

#set C++ version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Bring the headers into project
include_directories(includes)

#manually add sources or GLOB
#set(SOURCES src/gol.cpp src/run.cpp)

#GLOB
file(GLOB SOURCES "src/*.cpp")

# add the executable
add_executable(GameOfLife ${SOURCES})

#add file to configure version
#configure_file(GolConfig.h.in GolConfig.h)
