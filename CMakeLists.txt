cmake_minimum_required(VERSION 3.5)
project(KalmanFilter)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(gtests)
#add_subdirectory(Eigen)

find_package(Threads REQUIRED)
enable_testing()
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

file(GLOB SOURCES "src/*.h" "src/*.cpp" "src/Eigen/src/*.h" "src/Eigen/src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(runAllTests tests.cpp ${TEST_SOURCES} ${SOURCES})
add_executable(KalmanFilter main1.cpp ${SOURCES})

target_link_libraries(runAllTests gtest gtest_main)
add_test(AllTests runAllTests)
