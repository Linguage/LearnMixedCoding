# 混合编程项目工程总览

本项目集合了多个 C++, Fortran 以及混合语言编程的示例，旨在演示不同场景下的编译、构建和执行流程。项目利用 VS Code 的任务配置和 CMake 构建系统来简化开发过程。

## 目录结构概览

```
.
├── .vscode/                # VS Code 配置 (例如 tasks.json)
├── build/                  # 顶层 CMake 项目的默认构建输出目录
├── fortran_examples/       # Fortran 示例代码
├── hello/                  # 简单的 C++ 示例
├── LeetCpp/                # LeetCode C++ 练习
├── MixedCodingPFC/         # C++/Fortran/Python 混合编程示例
├── MixedProject/           # C++/Fortran 混合编程示例
├── multi_cpp_project/      # 多 C++ 文件项目示例
└── README.md               # 本文档
```

## VS Code 环境配置与任务

本工作区在 `.vscode/` 目录下包含了一些 Visual Studio Code 特有的配置文件，以帮助简化开发、构建和调试流程。

*   **`tasks.json`**: 定义了自定义任务，例如编译单个文件、运行 CMake 构建、执行程序等。这些任务可以通过 VS Code 的命令面板 (Cmd+Shift+P 或 Ctrl+Shift+P，然后输入 "Tasks: Run Task") 来访问和执行。本文档后续章节会详细介绍如何使用这些预定义的任务。
*   **`launch.json`** (如果存在): 定义了调试配置。允许您直接从 VS Code 启动和调试您的应用程序。您可以为不同的可执行文件或场景设置断点、监视变量等。
*   **`settings.json`** (如果存在): 允许您为当前工作区指定特定的 VS Code 设置，这些设置会覆盖用户级别的设置。例如，您可以配置特定的编译器路径、代码格式化选项或与特定语言相关的设置。

这些配置文件使得在不同开发者之间共享一致的开发环境和操作流程成为可能。

本工作区配置了 VS Code 任务，以方便编译和运行代码。这些任务定义在 `.vscode/tasks.json` 文件中（如果该文件存在于您的工作区配置中）。

主要的任务类型包括：

*   **C++ 编译与执行**:
    *   `Clang++: 生成活动文件`: 使用 Clang++ 编译当前打开的 C++ 文件。
    *   `Clang++:执行已编译程序`: 运行由上一个任务生成的 C++ 可执行文件。
*   **Fortran 编译与执行**:
    *   `Fortran: gfortran 编译活动文件`: 使用 gfortran 编译当前打开的 Fortran 文件。
    *   `执行已编译Fortran程序`: 运行由上一个任务生成的 Fortran 可执行文件。
*   **CMake 项目管理 (工作区根目录)**:
    *   `CMake: 配置项目`: 在顶层 `build` 目录中配置 CMake 项目。
    *   `CMake: 构建项目`: 构建在顶层 `build` 目录中配置的 CMake 项目。
    *   `CMake: 运行项目`: 运行顶层 CMake 项目生成的主可执行文件 (默认为 `build/main`)。
    *   `CMake: 清理项目`: 清理顶层 `build` 目录。
*   **CMake 项目管理 (当前文件所在目录)**:
    *   `CMake: 配置当前目录项目`: 针对包含当前打开文件的目录中的 `CMakeLists.txt` 运行 CMake 配置。输出到该目录下的 `build` 子目录。
    *   `CMake: 构建当前目录项目`: 构建由上一个任务配置的 CMake 项目。
    *   `CMake: 运行当前目录项目`: 运行当前目录 CMake 项目生成的可执行文件 (需要手动输入可执行文件名)。

**使用方法**:
1. 打开命令面板 (View > Command Palette... 或 `Cmd+Shift+P` / `Ctrl+Shift+P`)。
2. 输入 "Tasks: Run Task"。
3. 选择您想要执行的任务。

## 项目示例与构建指南

### 1. 简单的 C++ 和 Fortran 文件编译

对于单个 C++ (`.cpp`) 或 Fortran (`.f90`) 文件，您可以直接使用 VS Code 提供的编译任务：

*   打开您的 `.cpp` 文件，然后运行 `Clang++: 生成活动文件` 任务，接着运行 `Clang++:执行已编译程序` 任务。
*   打开您的 `.f90` 文件，然后运行 `Fortran: gfortran 编译活动文件` 任务，接着运行 `执行已编译Fortran程序` 任务。

编译后的可执行文件通常位于工作区根目录下的 `build/` 文件夹中。

### 2. CMake 项目

CMake 是一个跨平台的构建系统生成工具，用于管理项目的构建过程。

#### a. 多 C++ 文件项目 (`multi_cpp_project`)

此示例演示了如何使用 CMake 管理一个包含多个 C++ 源文件（例如，一个主程序和一些库文件）的项目。

*   **详细说明**: [multi_cpp_project/README.md](./multi_cpp_project/README.md)
*   **CMake 配置**: [multi_cpp_project/CMakeLists.txt](./multi_cpp_project/CMakeLists.txt)

**构建与运行 (使用 VS Code Tasks)**:
1. 打开 `multi_cpp_project/src/main.cpp` (或该项目下的任一文件)。
2. 运行 `CMake: 配置当前目录项目` 任务。
3. 运行 `CMake: 构建当前目录项目` 任务。
4. 运行 `CMake: 运行当前目录项目` 任务 (当提示输入可执行文件名时，通常是项目名，例如 `calculator_app`，具体请查看其 `CMakeLists.txt` 中 `add_executable` 的定义)。

**构建与运行 (手动命令行)**:
```bash
cd multi_cpp_project
mkdir build
cd build
cmake ..
cmake --build . # 或者 make
./bin/calculator_app # 假设可执行文件在 build/bin/calculator_app
```

#### b. C++ 与 Fortran 混合编程 (`MixedProject`)

此示例展示了如何配置 CMake 以编译和链接 C++ 与 Fortran 代码。

*   **详细说明**: [MixedProject/README.md](./MixedProject/README.md)
*   **CMake 配置**: [MixedProject/CMakeLists.txt](./MixedProject/CMakeLists.txt)

**构建与运行 (使用 VS Code Tasks)**:
1. 打开 `MixedProject/src/main.cpp` (或该项目下的任一文件)。
2. 运行 `CMake: 配置当前目录项目` 任务。
3. 运行 `CMake: 构建当前目录项目` 任务。
4. 运行 `CMake: 运行当前目录项目` 任务 (可执行文件名通常是 `MixedProject`，具体请查看其 `CMakeLists.txt`)。

**构建与运行 (手动命令行)**:
```bash
cd MixedProject
mkdir build
cd build
cmake ..
cmake --build . # 或者 make
./bin/MixedProject # 假设可执行文件在 build/bin/MixedProject
```

#### c. C++, Fortran 与 Python 混合项目 (`MixedCodingPFC`)

此示例演示了一个更复杂的场景，其中 C++ 和 Fortran 代码被编译成一个库或可执行文件，然后可能由 Python 脚本调用，或者 Python 脚本用于数据处理和绘图。

*   **详细说明**: [MixedCodingPFC/readme.md](./MixedCodingPFC/readme.md)
*   **CMake 配置**: [MixedCodingPFC/CMakeLists.txt](./MixedCodingPFC/CMakeLists.txt)

**构建与运行 (通常涉及 CMake 和 Python 脚本)**:
1.  **编译 C++/Fortran 部分**:
    *   打开 `MixedCodingPFC/main.cpp` (或该项目下的任一 C++/Fortran 文件)。
    *   运行 `CMake: 配置当前目录项目` 任务。
    *   运行 `CMake: 构建当前目录项目` 任务。
    *   可执行文件 (例如 `MixedCodingPFC_run`) 会生成在 `MixedCodingPFC/build/` 目录下。
2.  **运行 Python 脚本 (如果适用)**:
    *   根据 `MixedCodingPFC/readme.md` 中的指示，您可能需要直接运行 Python 脚本，例如 `python plot_result.py`。这个脚本可能会读取由 C++/Fortran 程序生成的数据文件。

**构建与运行 (手动命令行)**:
```bash
cd MixedCodingPFC
mkdir build
cd build
cmake ..
cmake --build . # 或者 make
./MixedCodingPFC_run # 运行 C++/Fortran 生成的可执行文件

# 如果有 Python 脚本，例如 plot_result.py
# python ../plot_result.py # 假设它在 MixedCodingPFC 目录下
```

## 其他示例

*   **`fortran_examples/`**: 包含一些独立的 Fortran 示例代码。可以直接使用 VS Code 的 Fortran 编译任务进行编译和运行。
*   **`hello/`**: 包含一些简单的 C++ "hello world" 类型的示例。可以使用 VS Code 的 C++ 编译任务进行编译和运行。
*   **`LeetCpp/`**: 包含一些 LeetCode C++ 练习题的解法。可以使用 VS Code 的 C++ 编译任务进行编译和运行。

## 编译器和环境要求

*   **C++ 编译器**: Clang++ (macOS 默认) 或 GCC/G++。
*   **Fortran 编译器**: gfortran (可以通过 Homebrew 在 macOS 上安装: `brew install gcc`).
*   **CMake**: 版本 3.10 或更高。
*   **Python**: (对于 `MixedCodingPFC` 项目) Python 3.x，以及 `matplotlib` 和 `numpy` 库 (可以通过 pip 安装: `pip install matplotlib numpy`).

确保这些工具已正确安装并配置在您的系统路径中。

---

祝您编码愉快！
