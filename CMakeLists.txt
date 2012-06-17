cmake_minimum_required(VERSION 2.8)

PROJECT(hypershell)

include_directories ("${PROJECT_SOURCE_DIR}")

SET(hysh_SRCS hysh/impl/default_allocator.c hysh/impl/SimpleDataBuffer.cpp main.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall")

ADD_EXECUTABLE(hysh ${hysh_SRCS})