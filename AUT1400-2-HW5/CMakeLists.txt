cmake_minimum_required(VERSION 4.0.2)

# 项目名称（注意：CMake 项目名不能有连字符，建议用下划线）
project(AUT1400_2_5 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# 添加 googletest 子模块（确保 googletest/ 目录存在）
add_subdirectory(googletest EXCLUDE_FROM_ALL)

# 定义可执行文件：AlgebraTests
add_executable(AlgebraTests
        src/cappuccino.cpp
        src/espresso_based.cpp
        src/main.cpp
        src/mocha.cpp
        src/unit_test.cpp
)

# 包含目录：你的项目头文件
target_include_directories(AlgebraTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include
)

# 链接 GoogleTest 库
target_link_libraries(AlgebraTests
        gtest_main
        gmock_main
)