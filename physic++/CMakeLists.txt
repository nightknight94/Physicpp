cmake_minimum_required (VERSION 3.10)

project (Physic++)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
FILE(GLOB_RECURSE physic_src *.cpp)
add_library(physic++ SHARED ${physic_src})