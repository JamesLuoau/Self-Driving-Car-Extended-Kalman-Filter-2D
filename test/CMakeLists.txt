project(ExtendedKF)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++0x)

add_subdirectory(test/lib/googletest-master)
include_directories(test/lib/googletest-master/googletest/include)
include_directories(test/lib/googletest-master/googlemock/include)

set(sources
    src/FusionEKF.cpp
    src/kalman_filter.cpp
    src/main.cpp
    src/tools.cpp test/DemoTest.cpp test/DemoTest.h)

add_executable(ExtendedKF ${sources} test/DemoTest.cpp test/DemoTest.h)

target_link_libraries(ExtendedKF gtest gtest_main)