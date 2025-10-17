cmake_minimum_required(VERSION 3.29)
project(AUT1400_2-1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

include_directories(include/)

add_executable(AlgebraTests
        src/unit_test.cpp
        include/6.2.hpp
        src/main.cpp
)

# 链接GTest库
target_link_libraries(AlgebraTests gtest gtest_main)

# 包含头文件（使用正确的路径）
target_include_directories(AlgebraTests PRIVATE
        ${CMAKE_SOURCE_DIR}/googletest/googletest/include
)
target_include_directories(AlgebraTests PRIVATE
        ${CMAKE_SOURCE_DIR}/googletest/googlemock/include
)