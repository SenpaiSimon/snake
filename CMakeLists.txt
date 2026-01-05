cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} 
  main.cpp
)

target_link_libraries(${PROJECT_NAME} 
    ${SDL2_LIBRARIES}
    Renderer
    KeyHandler
    SnakeObject
)

add_subdirectory(src)