cmake_minimum_required(VERSION 3.10)

set(LIBNAME IObject)

add_library(${LIBNAME} INTERFACE)

target_include_directories(${LIBNAME} INTERFACE 
    Include
)

add_subdirectory(Source)