cmake_minimum_required(VERSION 3.10)

set(LIBNAME KeyHandler)

add_library(${LIBNAME} 
    KeyHandler.cpp
)

target_include_directories(${LIBNAME} PUBLIC
    .
)