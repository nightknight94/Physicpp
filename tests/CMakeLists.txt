cmake_minimum_required (VERSION 3.10)

# TODO: include(GoogleTest)
project (gtests)

# Set path to googletest framework
set (gtest_path /home/damian/Documents/cpp_projects/googletest)
set (googletest_path ${gtest_path}/googletest)
set (googlemock_path ${gtest_path}/googlemock)

include_directories (${physic_path})
include_directories(${googletest_path}/include)
include_directories(${googlemock_path}/include)

# Create test executable
FILE(GLOB test_src ${test_path}/*.cpp)
add_executable(gtests ${test_src})
target_link_libraries(gtests 
                      physic++
					  ${googletest_path}/build/libgtest.a
					  ${googlemock_path}/build/libgmock.a
					  pthread)