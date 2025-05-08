#include <iostream>
#include <vector>
#include <iomanip> // 用于 std::setw

// 函数声明：打印杨辉三角
void printPascalsTriangle(int numRows);

int main() {
    int rows;
    std::cout << "请输入杨辉三角的行数: ";
    std::cin >> rows;

    // 检查输入是否有效
    if (std::cin.fail() || rows <= 0) {
        std::cout << "无效输入。请输入一个正整数作为行数。" << std::endl;
        // 清除错误标志并忽略剩余的无效输入
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // 返回错误码
    }

    printPascalsTriangle(rows);

    return 0;
}

// 函数定义：打印杨辉三角
void printPascalsTriangle(int numRows) {
    if (numRows <= 0) {
        // 主函数已经处理了这个问题，但作为防御性编程，这里可以再次检查
        return;
    }

    std::vector<std::vector<long long>> triangle(numRows);

    // 计算杨辉三角的数值
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1); // 第 i 行有 i+1 个元素 (0-indexed)
        triangle[i][0] = 1;        // 每行的第一个元素是 1
        triangle[i][i] = 1;        // 每行的最后一个元素是 1

        // 计算中间的元素
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // 确定打印时每个数字的单元格宽度
    // 这个宽度可以根据最大数字的位数动态调整，或者使用一个合理的固定值
    // 这里我们根据行数做一个简单的启发式调整
    int cellWidth = 4; // 默认宽度
    if (numRows > 5) cellWidth = 5;
    if (numRows > 9) cellWidth = 6;
    if (numRows > 13) cellWidth = 7;


    // 打印杨辉三角
    for (int i = 0; i < numRows; ++i) {
        // 打印前导空格以使每行居中
        // 第 i 行 (0-indexed) 前面需要的空格数，与 (numRows - 1 - i) 成正比
        // 每个 "空格单元" 大致相当于 cellWidth / 2 个实际空格
        int leadingSpaces = (numRows - 1 - i) * (cellWidth / 2);
        // 对于奇数 cellWidth，(cellWidth / 2) 会截断，可能需要微调，但通常效果尚可
        // 或者更简单地，(numRows - 1 - i) * K 个空格，K 是一个常数，例如 2 或 3
        // 这里我们使用 (numRows - 1 - i) * (cellWidth / 2)
        
        for (int s = 0; s < leadingSpaces; ++s) {
            std::cout << " ";
        }

        // 打印当前行的数字
        for (int j = 0; j <= i; ++j) {
            // std::setw(cellWidth) 设置字段宽度
            // 对于数字，默认是右对齐，这通常看起来不错
            std::cout << std::setw(cellWidth) << triangle[i][j];
        }
        std::cout << std::endl; // 每行结束后换行
    }
}
