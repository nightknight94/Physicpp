cmake_minimum_required (VERSION 3.0)

project (Physic++)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wshadow -fprofile-arcs -ftest-coverage")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(tests
				    COMMAND ${CMAKE_BINARY_DIR}/gtests
				    DEPENDS ${CMAKE_BINARY_DIR}/gtests)

add_custom_target(valgrind
					COMMAND valgrind ${CMAKE_BINARY_DIR}/gtests
					DEPENDS ${CMAKE_BINARY_DIR}/gtests)

add_custom_target(cppcheck
				    COMMAND cppcheck --enable=all -v -q ${CMAKE_SOURCE_DIR}/physic++/)

add_custom_target(full_test
				    COMMAND make tests
				    COMMAND make valgrind
				    COMMAND make cppcheck)

# Build shared library
set(physic_path ${CMAKE_SOURCE_DIR}/physic++)
FILE(GLOB physic_src ${physic_path}/*.cpp)
add_library(physic++ SHARED ${physic_src})

# Add the ‘include’ directory 
include_directories (${physic_path})

# Build tests
set(test_path ${CMAKE_SOURCE_DIR}/tests)
add_subdirectory(${test_path})

# Build playground
set(sfml sfml-graphics sfml-window sfml-system)

add_executable(example main.cpp)
target_link_libraries(example physic++ ${sfml})
