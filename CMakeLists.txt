cmake_minimum_required(VERSION 3.6)
project(CSCI333_final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp Student.h FileReader.cpp FileReader.h FileWriter.cpp FileWriter.h)
add_executable(CSCI333_final ${SOURCE_FILES})