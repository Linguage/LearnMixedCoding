
# 混合编程

使用CMake调用GCC与gfortran实现C++与Fortran的混合编程

## 目录结构

```
MixedCoding/
├── main.cpp           # C++ 主程序，调用 Fortran 并通过 Python 绘图
├── myfortran.f90      # Fortran 子程序，数值积分（PDE）
├── plot_result.py     # Python 脚本，读取数据并绘图
├── CMakeLists.txt     # CMake 构建配置
└── readme.md
```

## 环境准备

1. 请确保已安装 Anaconda/Miniconda，并创建名为 henri_env 的环境：

```sh
conda create -n henri_env python=3.10 matplotlib numpy
```

2. 激活环境（用于手动测试 Python 脚本）：

```sh
conda activate henri_env
```

## 编译与运行

1. 在 MixedCoding 目录下创建构建目录并进入：

```sh
mkdir build && cd build
```

2. 使用 CMake 配置并编译：

```sh
cmake ..
make
```

3. 运行可执行文件（自动调用 Python 绘图，环境自动切换）：

```sh
./mixed
```

## 功能说明

- myfortran.f90：Fortran 子程序，使用显式欧拉法积分一维热传导方程（PDE），结果通过参数返回。
- main.cpp：C++ 主程序，调用 Fortran 计算，将结果写入 data.txt，并自动调用 Python 脚本绘图。
- plot_result.py：Python 脚本，读取 data.txt 并用 matplotlib 绘制数值解。
- CMakeLists.txt：自动检测 C++ 和 Fortran 编译器，生成混合程序。

## 数据流

Fortran (PDE计算) → C++ (保存结果) → Python (matplotlib绘图)

## 预期输出

- 终端输出：
```
C++: 调用 Fortran 进行PDE数值计算...
C++: 计算完成，写入 data.txt...
C++: 调用 Python 脚本绘图...
```
- 弹出 matplotlib 窗口显示 PDE 数值解曲线。
