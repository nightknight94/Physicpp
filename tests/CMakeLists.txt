cmake_minimum_required (VERSION 3.0)

project (gtests)

# Include googletest
set (gtest_path ${test_path}/googletest/googletest)
add_subdirectory(${gtest_path} 
				 EXCLUDE_FROM_ALL)

include_directories (${physic_path})
include_directories (${gtest_path}/include)

# Create test executable
FILE(GLOB test_src ${test_path}/*.cpp)
add_executable(gtests ${test_path}/main.cpp ${test_src})
target_link_libraries(gtests physic++ gtest_main)
