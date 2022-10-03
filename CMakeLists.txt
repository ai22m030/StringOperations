cmake_minimum_required(VERSION 3.23)
project(StringOperations)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringOperations main.cpp src/String.cpp include/String.h)
