#include <iostream>

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

extern "C" {
    void pde_solver_(double* u, int* n);
}

int main() {
    const int n = 100;
    std::vector<double> u(n);
    int n_f = n;

    std::cout << "C++: 调用 Fortran 进行PDE数值计算..." << std::endl;
    pde_solver_(&u[0], &n_f);
    std::cout << "C++: 计算完成，写入 data.txt..." << std::endl;

    // 将数据写到上级目录 MixedCoding 下，保证 Python 脚本能访问
    std::ofstream fout("../data.txt");
    for (int i = 0; i < n; ++i) {
        fout << i << " " << u[i] << "\n";
    }
    fout.close();

    std::cout << "C++: 调用 Python 脚本绘图..." << std::endl;
    int ret = std::system("conda run -n henri_env python3 ../plot_result.py");
    if (ret != 0) {
        std::cerr << "Python 绘图失败，返回码：" << ret << std::endl;
    }
    return 0;
}
