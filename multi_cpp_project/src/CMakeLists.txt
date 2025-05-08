# 查找所有源文件
file(GLOB_RECURSE SOURCES "*.cpp")

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接计算器库
target_link_libraries(${PROJECT_NAME} PRIVATE calculator)

# 安装可执行文件
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)