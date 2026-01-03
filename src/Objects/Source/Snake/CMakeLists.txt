cmake_minimum_required(VERSION 3.10)

set(LIBNAME SnakeObject)

add_library(${LIBNAME} 
    Snake.cpp
)

target_include_directories(${LIBNAME} PUBLIC
    .
)

target_link_libraries(${LIBNAME} 
    PUBLIC
        IObject
)