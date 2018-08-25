cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wshadow")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(tests
					COMMAND ${CMAKE_BINARY_DIR}/gtests --gtest_color=yes
					DEPENDS gtests)

add_custom_target(valgrind
					COMMAND valgrind --tool=memcheck --leak-check=full ${CMAKE_BINARY_DIR}/gtests
					DEPENDS gtests)

# Add submodules
set(physic_path ${CMAKE_SOURCE_DIR}/physic++)
set(test_path ${CMAKE_SOURCE_DIR}/testing)

add_subdirectory(${test_path})
add_subdirectory(${physic_path})

# Build playground
set(sfml sfml-graphics sfml-window sfml-system)

# For convenience
include_directories (${physic_path}) 

add_executable(example main.cpp)
target_link_libraries(example physic++ ${sfml})
