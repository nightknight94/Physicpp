cmake_minimum_required (VERSION 3.10)

project (gtests)

# Include googletest
set (gtest_path ${CMAKE_SOURCE_DIR}/googletest)
add_subdirectory(${gtest_path} 
 				 ${gtest_path} 
 				 EXCLUDE_FROM_ALL)

include_directories (${physic_path})

# Create test executable
FILE(GLOB test_src ${test_path}/*.cpp)
add_executable(gtests ${test_path}/main.cpp ${test_src})
target_link_libraries(gtests physic++ gtest_main)
