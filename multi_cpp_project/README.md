# Multi-File C++ Calculator Project

## 简介

本项目是一个简单的C++计算器示例，旨在演示如何使用CMake组织、编译和管理一个包含多个源文件和库的多文件C++项目。

## 目录结构

```
multi_cpp_project/
├── CMakeLists.txt          # 顶层CMake配置文件
├── build/                  # (构建后生成) 存放编译产物
├── include/
│   └── calculator.h        # 计算器类的头文件，定义接口
├── lib/
│   ├── CMakeLists.txt      # lib子目录的CMake配置文件
│   └── calculator.cpp      # 计算器类的实现
├── src/
│   ├── CMakeLists.txt      # src子目录的CMake配置文件
│   └── main.cpp            # 主程序入口，使用计算器类
└── test/                   # (可选) 存放测试代码
    ├── CMakeLists.txt      # test子目录的CMake配置文件
    └── calculator_test.cpp # 计算器类的单元测试
```

-   `include/`: 存放项目共用的头文件。`calculator.h` 定义了 `Calculator` 类的接口。
-   `lib/`: 存放库代码。`calculator.cpp` 是 `Calculator` 类的实现，它将被编译成一个静态库。
-   `src/`: 存放主程序代码。`main.cpp` 包含 `main` 函数，它会使用 `Calculator` 库。
-   `CMakeLists.txt`: CMake构建系统的配置文件。每个主要目录（顶层、`lib`、`src`、`test`）都有一个。
-   `build/`: 这个目录在运行CMake和构建过程后自动生成，用于存放所有编译中间文件和最终的可执行文件/库。

## 先决条件

-   C++ 编译器 (例如 GCC, Clang, MSVC)
-   CMake (版本 3.10 或更高)

## 构建和运行项目

1.  **创建并进入构建目录**:
    ```bash
    mkdir -p build
    cd build
    ```
    *建议在项目根目录之外或指定的 `build` 目录中进行构建，以保持源码树的清洁。本项目配置为在 `multi_cpp_project/build` 中构建。*

2.  **配置项目 (运行 CMake)**:
    在 `multi_cpp_project/build` 目录下执行：
    ```bash
    cmake ..
    ```
    或者，从 `multi_cpp_project` 根目录执行：
    ```bash
    cmake -S . -B build
    ```
    此命令会读取顶层的 `CMakeLists.txt` 文件，配置项目并生成特定于你的构建环境的构建文件 (例如 Makefiles 或 Ninja 文件)。

3.  **编译项目**:
    在 `multi_cpp_project/build` 目录下执行：
    ```bash
    cmake --build .
    ```
    或者，如果生成的是 Makefiles (Linux/macOS 常见)：
    ```bash
    make
    ```
    此命令会编译库和可执行文件。编译后的可执行文件将位于 `multi_cpp_project/build/bin/` 目录下，库文件位于 `multi_cpp_project/build/lib/`。

4.  **运行可执行文件**:
    在 `multi_cpp_project/build` 目录下执行：
    ```bash
    ./bin/MultiCppProject
    ```
    或者从项目根目录执行：
    ```bash
    ./build/bin/MultiCppProject
    ```

## 多C++文件项目的运行逻辑

### 1. 接口与实现分离
-   **头文件 (`.h`, `.hpp`)**: 用于声明。它们定义了类、函数、常量等的“契约”或接口，但不包含具体的实现代码。在本项目中，`include/calculator.h` 声明了 `Calculator` 类及其成员函数。
-   **源文件 (`.cpp`)**: 用于实现。它们包含在头文件中声明的类和函数的实际代码。`lib/calculator.cpp` 实现了 `Calculator` 类的功能。

### 2. 编译过程
-   **预处理**: 处理 `#include`, `#define` 等预处理指令。
-   **编译**: 每个 `.cpp` 源文件被编译器独立编译成一个目标文件 (`.o` 或 `.obj`)。目标文件包含机器码，但此时函数和变量的地址可能尚未解析（特别是那些在其他文件中定义的）。
    -   `lib/calculator.cpp` -> `calculator.o`
    -   `src/main.cpp` -> `main.o`
-   **链接**: 链接器将所有相关的目标文件以及所需的库文件组合起来，解析符号引用（例如，`main.o` 中对 `Calculator` 类方法的调用），并创建一个最终的可执行文件。
    -   `main.o` + `libcalculator.a` (静态库) -> `MultiCppProject` (可执行文件)

### 3. CMake的角色
CMake 是一个构建系统生成器。它不直接编译代码，而是根据 `CMakeLists.txt` 文件中的指令生成用于实际构建工具（如 Make, Ninja, Visual Studio）的配置文件。

-   **`multi_cpp_project/CMakeLists.txt` (顶层)**:
    -   设置项目名称、C++标准等。
    -   使用 `add_subdirectory(lib)` 和 `add_subdirectory(src)` 指令来包含其他目录中的 `CMakeLists.txt` 文件，从而处理这些模块。
    -   设置头文件包含目录 (`include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)`)，以便编译器可以找到 `calculator.h`。

-   **`multi_cpp_project/lib/CMakeLists.txt`**:
    -   使用 `file(GLOB_RECURSE LIB_SOURCES "*.cpp")` 查找所有 `.cpp` 文件。
    -   使用 `add_library(calculator STATIC ${LIB_SOURCES})` 将 `calculator.cpp` 编译成一个名为 `calculator` 的静态库 (`libcalculator.a`)。
    -   使用 `target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include)` 指定该库的目标需要 `include` 目录下的头文件，并且任何链接到此库的目标也应该自动获得此包含目录。

-   **`multi_cpp_project/src/CMakeLists.txt`**:
    -   使用 `file(GLOB_RECURSE SOURCES "*.cpp")` 查找所有 `.cpp` 文件。
    -   使用 `add_executable(${PROJECT_NAME} ${SOURCES})` 将 `main.cpp` 编译成一个可执行文件。
    -   使用 `target_link_libraries(${PROJECT_NAME} PRIVATE calculator)` 指示链接器将 `MultiCppProject` 可执行文件与 `calculator` 库链接起来。`PRIVATE` 表示只有 `MultiCppProject` 直接使用 `calculator`，而链接到 `MultiCppProject` 的其他目标不会自动链接到 `calculator`。

## 操作要点

1.  **头文件守卫 (Include Guards)**:
    在 `calculator.h` 中使用了 `#pragma once`。这是一种常见的头文件守卫，用于防止同一个头文件在一次编译中被多次包含，从而避免重复定义错误。另一种传统方法是使用 `#ifndef MY_HEADER_H` / `#define MY_HEADER_H` / `#endif`。

2.  **清晰的目录结构**:
    将接口（`.h` 文件在 `include/`）、库实现（`.cpp` 文件在 `lib/`）和主程序（`.cpp` 文件在 `src/`）分开存放，有助于保持项目组织清晰和模块化。

3.  **CMake 的使用**:
    -   **`add_library()`**: 用于从源文件创建库。
    -   **`add_executable()`**: 用于从源文件创建可执行文件。
    -   **`target_link_libraries()`**: 用于指定可执行文件或库所依赖的其他库。
    -   **`target_include_directories()`**: 用于为目标（库或可执行文件）指定头文件搜索路径。`PUBLIC` 关键字意味着链接到此目标的其他目标也会继承这些包含目录。`INTERFACE` 意味着只有链接到此目标的其他目标会继承。`PRIVATE` 意味着只有此目标本身使用这些包含目录。
    -   **`add_subdirectory()`**: 将子目录中的 `CMakeLists.txt` 文件包含到构建过程中，实现模块化构建。

4.  **构建分离 (Out-of-Source Build)**:
    始终在源代码目录之外的独立目录（如 `build/`）中运行 CMake 和编译。这可以保持源代码目录的清洁，并允许轻松删除所有构建产物。

5.  **依赖管理**:
    当 `main.cpp` `#include "calculator.h"` 时，编译器需要知道在哪里找到这个头文件。CMake 中的 `target_include_directories` 解决了这个问题。在链接阶段，`main` 函数中对 `Calculator` 方法的调用需要被解析，`target_link_libraries` 确保可执行文件与实现了这些方法的库正确链接。

通过遵循这些原则和使用CMake，可以有效地管理具有多个文件和依赖关系的C++项目。
