cmake_minimum_required(VERSION 3.11)

project(SDL2Game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(lib)
add_subdirectory(src)
