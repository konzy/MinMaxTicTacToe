cmake_minimum_required(VERSION 3.6)
project(konzmanb1FinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.h MinMaxNode.cpp MinMaxNode.h)
add_executable(konzmanb1FinalProject ${SOURCE_FILES})