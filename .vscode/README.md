# VS Code 项目配置说明

## 功能概述

本项目的 VS Code 配置主要用于支持 C/C++ 和 Fortran 开发环境，提供了自动化的编译、执行和调试功能。通过预设任务（Tasks）和启动配置（Launch），简化了多语言项目的开发流程。

## 配置文件说明

`.vscode` 目录包含以下配置文件：

- `tasks.json`: 定义编译和执行任务
- `launch.json`: 定义调试配置 (如需调试功能请添加此文件)
- `settings.json`: 项目特定的编辑器设置 (可选)
- `c_cpp_properties.json`: C/C++ 扩展配置 (可选)

## 任务（Tasks）功能

本项目包含以下预定义任务：

1. **创建build目录**
   - 功能：自动创建 build 目录用于存放编译产物
   - 作为其他编译任务的依赖项自动执行

2. **C/C++: clang++ 生成活动文件**
   - 功能：编译当前打开的 C/C++ 源文件
   - 语法标准：C++17
   - 输出：在 build 目录中生成与源文件同名的可执行文件
   - 包含调试信息（-g 参数）

3. **执行已编译程序**
   - 功能：执行编译后的 C/C++ 程序
   - 依赖：自动触发编译任务

4. **Fortran: gfortran 编译活动文件**
   - 功能：编译当前打开的 Fortran 源文件
   - 输出：在 build 目录中生成与源文件同名的可执行文件
   - 包含调试信息

5. **执行已编译Fortran程序**
   - 功能：执行编译后的 Fortran 程序

### CMake 相关任务

除了上述通用的编译和执行任务外，还针对 CMake 项目提供了更细致的任务：

1.  **CMake: 配置项目**
    *   功能：配置位于工作区根目录的 CMake 项目。
    *   源目录：`${workspaceFolder}`
    *   构建目录：`${workspaceFolder}/build`
    *   构建类型：Debug

2.  **CMake: 构建项目**
    *   功能：构建通过 "CMake: 配置项目" 配置的 CMake 项目。
    *   依赖："CMake: 配置项目"

3.  **CMake: 运行项目**
    *   功能：运行工作区根目录下构建的名为 `main` 的可执行文件。
    *   依赖："CMake: 构建项目"
    *   可执行文件路径：`${workspaceFolder}/build/main`

4.  **CMake: 清理项目**
    *   功能：清理工作区根目录 CMake 项目的构建目录 (`${workspaceFolder}/build`)。

5.  **CMake: 配置当前目录项目**
    *   **适用场景**：当您的工作区包含多个独立的子项目，每个子项目都有自己的 `CMakeLists.txt` 文件时（例如 `multi_cpp_project` 示例）。
    *   功能：配置当前打开文件所在目录下的 CMake 项目。
    *   源目录：`${fileDirname}` (当前文件所在目录)
    *   构建目录：`${fileDirname}/build`
    *   构建类型：Debug
    *   **使用方法**：打开子项目中的任意文件（如 `multi_cpp_project/src/main.cpp` 或 `multi_cpp_project/CMakeLists.txt`），然后从命令面板运行此任务。

6.  **CMake: 构建当前目录项目**
    *   **适用场景**：同上，用于构建已配置的子项目。
    *   功能：构建通过 "CMake: 配置当前目录项目" 配置的 CMake 项目。
    *   依赖："CMake: 配置当前目录项目"
    *   **使用方法**：确保已先运行 "CMake: 配置当前目录项目"，然后从命令面板运行此任务。

7.  **CMake: 运行当前目录项目**
    *   **适用场景**：同上，用于运行子项目中生成的可执行文件。
    *   功能：运行当前文件所在目录 CMake 项目构建生成的可执行文件。
    *   依赖："CMake: 构建当前目录项目"
    *   可执行文件路径：`${fileDirname}/build/bin/${input:executableName}`
    *   **使用方法**：
        *   确保已成功构建子项目。
        *   从命令面板运行此任务。
        *   系统会提示您输入可执行文件的名称。默认情况下，它会使用当前文件所在目录的名称 (例如，如果您在 `multi_cpp_project` 目录中，默认会是 `multi_cpp_project`)。如果您的 CMakeLists.txt 中定义的可执行文件名不同，请输入正确的名称。

## 使用方法

### 编译和运行 C/C++ 程序

1. 打开要编译的 `.cpp` 或 `.c` 文件
2. 使用以下方法之一触发任务：
   - 按下 `Ctrl+Shift+B`（默认构建快捷键）
   - 命令面板（`Ctrl+Shift+P`）中选择 "Run Build Task"
   - 终端菜单 → "Run Build Task"
3. 如需执行编译后的程序：
   - 命令面板中选择 "Run Test Task"
   - 选择 "执行已编译程序" 任务

### 编译和运行 Fortran 程序

1. 打开要编译的 `.f90` 或 `.f` 文件
2. 命令面板中选择 "Run Task"
3. 选择 "Fortran: gfortran 编译活动文件" 任务
4. 运行程序时选择 "执行已编译Fortran程序" 任务

### 使用 CMake 项目

#### 1. 针对工作区根目录的 CMake 项目：

*   **配置项目**：
    1.  打开命令面板 (`Cmd+Shift+P` 或 `Ctrl+Shift+P`)。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 配置项目`。
*   **构建项目**：
    1.  打开命令面板。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 构建项目`。
*   **运行项目** (假设可执行文件名为 `main`)：
    1.  打开命令面板。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 运行项目`。
*   **调试项目** (假设可执行文件名为 `main`，且 `launch.json` 中有对应配置如 "CMake: Debug")：
    1.  打开调试视图。
    2.  选择 "CMake: Debug" 配置。
    3.  按 F5 或点击绿色播放按钮。

#### 2. 针对子目录中的 CMake 项目 (例如 `multi_cpp_project`)：

*   **打开子项目中的文件**：首先，在 VS Code 编辑器中打开位于子项目目录（例如 `multi_cpp_project/src/main.cpp`）中的任何一个文件。这是为了让 `${fileDirname}` 变量能够正确解析到子项目的路径。
*   **配置子项目**：
    1.  打开命令面板。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 配置当前目录项目`。
*   **构建子项目**：
    1.  打开命令面板。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 构建当前目录项目`。
*   **运行子项目**：
    1.  打开命令面板。
    2.  输入并选择 `Tasks: Run Task`。
    3.  选择 `CMake: 运行当前目录项目`。
    4.  当提示输入可执行文件名时，输入您在子项目的 `CMakeLists.txt` 中定义的可执行文件名（例如 `MultiCppProject` 或 `calculator_test`）。默认会使用子目录的名称。
*   **调试子项目** (且 `launch.json` 中有对应配置如 "CMake: Debug 当前目录项目")：
    1.  确保已在子项目中打开一个文件。
    2.  打开调试视图。
    3.  选择 "CMake: Debug 当前目录项目" 配置。
    4.  当提示输入可执行文件名时，输入正确的名称。
    5.  按 F5 或点击绿色播放按钮。

## 配置原理和构建原则

### 构建原则

1. **分离编译与执行**
   - 编译和执行被分为独立任务，方便调试和检查中间结果

2. **统一输出目录**
   - 所有编译产物统一输出到 `build` 目录
   - 避免源代码目录被编译产物污染

3. **语言无关的工作流**
   - 为不同语言（C/C++、Fortran）提供相同的工作流体验
   - 降低在多语言项目中切换的认知负担

4. **依赖自动化**
   - 通过任务依赖关系（dependsOn）确保前置任务自动完成
   - 例如：运行程序前自动完成编译，编译前自动创建必要的目录

### 技术实现

任务定义采用 VS Code 的任务系统（Task System），主要设计思路：

1. **Shell 命令执行**：所有任务通过 shell 命令执行，确保可在终端复现
2. **变量替换**：使用 VS Code 预定义变量如 `${file}`、`${workspaceFolder}` 等实现灵活配置
3. **任务分组**：通过 `group` 属性将任务归类为 "build" 或 "test"，便于快捷键绑定
4. **任务依赖**：通过 `dependsOn` 属性建立任务间的依赖关系

## 扩展建议

为了获得最佳体验，建议安装以下 VS Code 扩展：

- **C/C++**：提供智能补全、语法高亮、调试等功能
- **Modern Fortran**：提供 Fortran 语法支持
- **Code Runner**：快速运行代码片段

## 自定义配置

您可以根据项目需求修改以下配置：

1. 在 `tasks.json` 中调整编译器参数、优化级别等
2. 添加新的编译或运行任务
3. 创建或修改 `launch.json` 以添加调试配置

## 代码片段（Snippets）使用指南

本项目配置了适用于 C/C++ 和 Fortran 开发的代码片段，可显著提高编码效率。

### 什么是代码片段

代码片段是可以快速插入编辑器的预定义代码模板，通过简短的触发前缀调用。

### 如何使用代码片段

1. 在编辑器中输入触发前缀（如 `main`）
2. 编辑器会显示匹配的代码片段列表
3. 按 `Tab` 或 `Enter` 插入所选代码片段
4. 使用 `Tab` 在代码片段的可编辑位置间跳转

### 可用的代码片段

以下是本项目预配置的一些代码片段，您可以在相应的语言环境中使用它们来提高编码效率。

#### C/C++ 代码片段 (`.vscode/cpp.code-snippets`)

| 触发前缀        | 描述                                           |
|-----------------|------------------------------------------------|
| `cppstd`        | 标准C++程序模板，包含常用头文件和main函数        |
| `cppclass`      | C++类定义模板，包含基本的类结构                  |
| `cppfast`       | 竞赛用C++模板，包含快速输入输出设置              |
| `cppalgo`       | 包含算法函数的C++程序模板                        |
| `cppheader`     | C++头文件模板，包含头文件保护和命名空间            |
| `cpphello`      | 最基础的C++ Hello World程序，用于测试C++环境     |
| `cppleetcode`   | LeetCode题目解题模板，包含Solution类和测试功能   |
| `cppcodforces`  | CodeForces竞赛专用模板，包含常用宏定义和多测试用例处理 |

#### Fortran 代码片段 (`.vscode/fortran.code-snippets`)

| 触发前缀        | 描述                               |
|-----------------|------------------------------------|
| `f90program`    | 基本的Fortran程序结构                |
| `f90module`     | Fortran模块结构                      |
| `f90function`   | Fortran函数结构                      |
| `f90subroutine` | Fortran子程序结构                    |
| `f90do`         | Fortran do循环结构                   |
| `f90dowhile`    | Fortran do while循环结构             |
| `f90if`         | Fortran if语句结构                   |
| `f90ifelse`     | Fortran if-else语句结构              |
| `f90ifelseif`   | Fortran if-elseif-else语句结构       |
| `f90select`     | Fortran select case语句结构          |
| `f90array`      | Fortran数组声明                      |
| `f90allocarray` | Fortran可分配数组声明和分配          |
| `f90openfile`   | 打开文件                             |
| `f90closefile`  | 关闭文件                             |
| `f90writefile`  | 写入文件                             |
| `f90readfile`   | 从文件读取                           |
| `f90matmul`     | 矩阵乘法                             |
| `f90mpiinit`    | MPI初始化和终止                      |
| `f90ompparallel`| OpenMP并行区域                       |
| `f90ompdo`      | OpenMP并行循环                       |

#### CMake 代码片段 (`.vscode/cmake.code-snippets`)

| 触发前缀              | 描述                             |
|-----------------------|----------------------------------|
| `cmake-basic`         | 基础 CMake 项目模板                |
| `cmake-mixed`         | C++/Fortran 混合项目模板         |
| `cmake-exe`           | 添加可执行文件目标                 |
| `cmake-lib`           | 添加库目标                         |
| `cmake-link`          | 为目标链接库                       |
| `cmake-find`          | 查找并链接外部包                   |
| `cmake-add-subdir`    | 添加子目录                         |
| `cmake-compile-options` | 为目标设置编译选项                 |
| `cmake-single-exe`    | 从当前文件创建可执行文件           |

### 自定义代码片段

您可以通过以下步骤创建自己的代码片段：

1. 打开命令面板（`Ctrl+Shift+P` 或 `Cmd+Shift+P`）
2. 输入并选择 "Preferences: Configure User Snippets"
3. 选择语言（如 "C", "C++" 或 "Fortran"）或创建新的代码片段文件
4. 按以下格式添加新的代码片段：

```json
"片段名称": {
  "prefix": "触发前缀",
  "body": [
    "第一行",
    "第二行",
    "${1:可选占位符}"
  ],
  "description": "片段描述"
}
```

### 代码片段技巧

- 使用 `${1:默认文本}`, `${2:默认文本}` 等创建可编辑占位符
- 使用 `$0` 设置最终光标位置
- 在快速插入重复代码模式时，代码片段比复制粘贴更高效
- 为常用的代码模式创建自定义片段，提高开发效率
