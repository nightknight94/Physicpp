cmake_minimum_required (VERSION 3.10)

project (Physic++)

FILE(GLOB physic_src ${
	CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(physic++ SHARED ${physic_src})