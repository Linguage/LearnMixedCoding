#include "calculator.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "多文件C++计算器示例" << std::endl;
  std::cout << "===================" << std::endl;

  Calculator calc;

  double a = 10.0;
  double b = 5.0;

  std::cout << "计算演示：" << std::endl;
  std::cout << a << " + " << b << " = " << calc.add(a, b) << std::endl;
  std::cout << a << " - " << b << " = " << calc.subtract(a, b) << std::endl;
  std::cout << a << " * " << b << " = " << calc.multiply(a, b) << std::endl;
  std::cout << a << " / " << b << " = " << calc.divide(a, b) << std::endl;

  // 高级计算
  std::cout << "\n高级计算：" << std::endl;
  std::cout << a << "² = " << calc.square(a) << std::endl;
  std::cout << "√" << a << " = " << calc.squareRoot(a) << std::endl;

  return 0;
}