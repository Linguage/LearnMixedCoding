cmake_minimum_required(VERSION 3.10)
project(MixedCoding LANGUAGES CXX Fortran)

add_executable(mixed main.cpp myfortran.f90)

# 确保链接 Fortran runtime（大多数情况下 CMake 会自动处理）
set_target_properties(mixed PROPERTIES LINKER_LANGUAGE CXX)
