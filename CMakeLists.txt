cmake_minimum_required(VERSION 3.7)
project(TrabajoPracticoTaller)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(MarvelVSCapcom WIN32 main.cpp)
target_link_libraries(untitled ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
