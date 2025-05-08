# C++ 与 Fortran 混合编程示例 (MixedProject)

本项目演示了如何使用 CMake 构建一个混合了 C++ 和 Fortran 代码的应用程序。

## 原理概述

C++ 与 Fortran 混合编程的核心在于建立一个清晰的接口，使得两种语言的代码能够相互调用。主要涉及以下几个方面：

1.  **名称修饰 (Name Mangling)**:
    *   C++ 编译器会对函数名进行修饰（例如，添加参数类型信息），而 Fortran 编译器通常会将子程序名转换为全小写，并可能根据调用约定添加下划线（例如，`my_subroutine` 变为 `my_subroutine_`）。
    *   为了确保 C++ 能够正确链接到 Fortran 子程序，需要在 C++ 代码中使用 `extern "C"` 来告诉 C++ 编译器按照 C 语言的约定处理函数名，从而避免名称修饰。

2.  **调用约定 (Calling Convention)**:
    *   Fortran 默认情况下参数是通过引用传递的。因此，在 C++ 中调用 Fortran 子程序时，需要传递参数的地址（指针）。
    *   了解编译器如何处理函数名和参数传递对于成功链接至关重要。不同的 Fortran 编译器可能有不同的默认行为（例如，gfortran 通常将名称转为小写并附加一个下划线）。

3.  **数据类型兼容性**:
    *   需要确保 C++ 和 Fortran 使用的数据类型是兼容的。例如，C++ 的 `int` 通常对应 Fortran 的 `INTEGER`。
    *   对于更复杂的数据类型（如数组、字符串、结构体/派生类型），需要特别注意其内存布局和传递方式。

4.  **接口声明 (Interface Header)**:
    *   在 C++ 代码中，通常会创建一个头文件（例如本项目中的 `include/fortran_interface.h`）来声明 Fortran 子程序的原型。这个头文件会使用 `extern "C"`。
    *   为了简化 C++ 代码的调用，可以在头文件中提供一个内联的 C++ 包装函数，该函数内部处理 Fortran 函数名的具体修饰（例如，调用 `add_integers_fortran_` 而不是直接让 C++ 主程序调用带下划线的版本）。

## 项目结构

```
MixedProject/
├── CMakeLists.txt          # CMake 构建脚本
├── fortran/                # Fortran 源代码目录
│   └── add_module.f90      # Fortran 加法子程序
├── include/                # C++ 头文件目录
│   └── fortran_interface.h # C++/Fortran 接口头文件
├── src/                    # C++ 源代码目录
│   └── main.cpp            # C++ 主程序
└── README.md               # 本文档
```

## 操作方式

### 先决条件

确保您的系统上安装了以下软件：

*   CMake (版本 3.10 或更高)
*   C++ 编译器 (例如 GCC/G++, Clang)
*   Fortran 编译器 (例如 gfortran)

### 构建步骤

可以使用 CMake 从命令行构建项目。打开终端，导航到 `MixedProject` 目录，然后执行以下命令：

1.  **创建构建目录并进入**:
    ```bash
    mkdir build
    cd build
    ```

2.  **配置项目 (生成构建系统)**:
    ```bash
    cmake ..
    ```
    此命令会读取顶层的 `CMakeLists.txt` 文件，并为您的平台生成相应的构建文件（例如 Makefile）。

3.  **编译项目**:
    ```bash
    cmake --build .
    # 或者直接使用 make (如果在上一步生成了 Makefile)
    # make
    ```
    编译成功后，可执行文件将位于 `MixedProject/build/bin/` 目录下，名为 `MixedProject`。

### 运行程序

构建完成后，可以直接运行生成的可执行文件：

```bash
./bin/MixedProject
```

您应该会看到来自 C++ 和 Fortran 代码的输出。

### 使用 VS Code Tasks (如果适用)

如果您在 VS Code 中打开此项目，并且配置了相应的 CMake tasks，您可以使用这些 tasks 来简化配置、构建和运行的流程。

例如，您可能会有如下任务：
*   `CMake: 配置当前目录项目`
*   `CMake: 构建当前目录项目`
*   `CMake: 运行当前目录项目` (运行时可能需要您输入可执行文件名，此处为 `MixedProject`)

## 代码说明

*   **`src/main.cpp`**: C++ 主程序。它包含了 `fortran_interface.h` 并调用 `add_integers_fortran` 函数（该函数是 `add_integers_fortran_` 的一个包装）。
*   **`fortran/add_module.f90`**: Fortran 源文件。它定义了一个名为 `add_integers_fortran` 的子程序，该子程序接收两个整数输入并返回它们的和。
*   **`include/fortran_interface.h`**: C++ 头文件。它使用 `extern "C"` 声明了 Fortran 子程序 `add_integers_fortran_` (注意末尾的下划线，这是 gfortran 的常见做法)。它还提供了一个内联函数 `add_integers_fortran` 作为 C++ 代码调用的友好接口，隐藏了名称修饰的细节。
*   **`CMakeLists.txt`**: CMake 配置文件。
    *   `project(MixedProject LANGUAGES CXX Fortran)`: 声明项目名称并启用 C++ 和 Fortran 语言支持。
    *   `file(GLOB_RECURSE ...)`: 查找源文件。
    *   `add_executable(MixedProject ...)`: 定义要生成的可执行文件及其源文件。
    *   `target_include_directories(MixedProject PRIVATE include)`: 将 `include` 目录添加到头文件搜索路径中，这样 `main.cpp` 才能找到 `fortran_interface.h`。

这个项目提供了一个基础模板，您可以基于此扩展更复杂的 C++/Fortran 混合应用程序。
