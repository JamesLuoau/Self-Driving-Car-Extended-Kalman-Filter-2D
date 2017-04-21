project(ExtendedKFTest)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++0x)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(test/DemoTest.cpp test/DemoTest.h)

add_executable(ExtendedKF ${sources} test/DemoTest.cpp test/DemoTest.h)

target_link_libraries(ExtendedKF gtest gtest_main)