cmake_minimum_required(VERSION 3.10)
project(MixedProject LANGUAGES CXX Fortran)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用 Fortran 支持
# enable_language(Fortran) # LANGUAGES CXX Fortran 已经启用了

# 设置构建类型
set(CMAKE_BUILD_TYPE Debug)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # 修正输出目录，并确保可执行文件在bin子目录中
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 静态库
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 动态库


# 查找 C++ 源文件
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")

# 查找 Fortran 源文件
file(GLOB_RECURSE FORTRAN_SOURCES "fortran/*.f90" "fortran/*.f")

# 添加主可执行文件
add_executable(MixedProject ${CPP_SOURCES} ${FORTRAN_SOURCES})

# 添加包含目录
target_include_directories(MixedProject PRIVATE include)