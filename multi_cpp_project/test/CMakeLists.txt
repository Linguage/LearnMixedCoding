# 查找所有测试源文件
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

# 创建测试可执行文件
add_executable(calculator_test ${TEST_SOURCES})

# 链接计算器库
target_link_libraries(calculator_test PRIVATE calculator)

# 添加测试
enable_testing()
add_test(NAME calculator_test COMMAND calculator_test)