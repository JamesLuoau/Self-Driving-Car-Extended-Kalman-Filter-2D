include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicCalendarTests
        basic_check.cpp)

target_link_libraries(runBasicCalendarTests gtest gtest_main)
