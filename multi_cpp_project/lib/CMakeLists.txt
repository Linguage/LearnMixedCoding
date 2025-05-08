# 查找所有源文件
file(GLOB_RECURSE LIB_SOURCES "*.cpp")

# 创建静态库
add_library(calculator STATIC ${LIB_SOURCES})

# 指定头文件目录
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include)

# 安装库文件
install(TARGETS calculator
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)