cmake_minimum_required(VERSION 3.10)
project(MultiCppProject VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 设置构建类型（如果未指定）
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加库子目录
add_subdirectory(lib)

# 添加源代码子目录
add_subdirectory(src)

# 添加测试子目录（可选）
option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()

# 打印配置信息
message(STATUS "项目配置信息:")
message(STATUS "  项目名称: ${PROJECT_NAME}")
message(STATUS "  项目版本: ${PROJECT_VERSION}")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ 编译器: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  C++ 标准: ${CMAKE_CXX_STANDARD}")