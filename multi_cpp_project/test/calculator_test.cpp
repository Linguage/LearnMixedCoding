#include "calculator.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// 简单的测试框架
#define TEST(name) void name()
#define EXPECT_NEAR(a, b, epsilon) assert(std::abs((a) - (b)) < epsilon)
#define EXPECT_THROW(expr, exception)                                          \
  {                                                                            \
    bool thrown = false;                                                       \
    try {                                                                      \
      expr;                                                                    \
    } catch (const exception &) {                                              \
      thrown = true;                                                           \
    }                                                                          \
    assert(thrown);                                                            \
  }

// 测试用例
TEST(testAdd) {
  Calculator calc;
  EXPECT_NEAR(calc.add(2, 3), 5, 1e-10);
  EXPECT_NEAR(calc.add(-2, 3), 1, 1e-10);
  EXPECT_NEAR(calc.add(2.5, 3.5), 6, 1e-10);
}

TEST(testSubtract) {
  Calculator calc;
  EXPECT_NEAR(calc.subtract(5, 3), 2, 1e-10);
  EXPECT_NEAR(calc.subtract(3, 5), -2, 1e-10);
  EXPECT_NEAR(calc.subtract(-2, -3), 1, 1e-10);
}

TEST(testMultiply) {
  Calculator calc;
  EXPECT_NEAR(calc.multiply(2, 3), 6, 1e-10);
  EXPECT_NEAR(calc.multiply(-2, 3), -6, 1e-10);
  EXPECT_NEAR(calc.multiply(2.5, 4), 10, 1e-10);
}

TEST(testDivide) {
  Calculator calc;
  EXPECT_NEAR(calc.divide(6, 3), 2, 1e-10);
  EXPECT_NEAR(calc.divide(5, 2), 2.5, 1e-10);
  EXPECT_THROW(calc.divide(1, 0), std::invalid_argument);
}

TEST(testSquare) {
  Calculator calc;
  EXPECT_NEAR(calc.square(4), 16, 1e-10);
  EXPECT_NEAR(calc.square(-3), 9, 1e-10);
  EXPECT_NEAR(calc.square(2.5), 6.25, 1e-10);
}

TEST(testSquareRoot) {
  Calculator calc;
  EXPECT_NEAR(calc.squareRoot(16), 4, 1e-10);
  EXPECT_NEAR(calc.squareRoot(2), 1.4142135623730951, 1e-10);
  EXPECT_THROW(calc.squareRoot(-1), std::domain_error);
}

// 运行所有测试
int main() {
  std::cout << "运行计算器测试..." << std::endl;

  try {
    testAdd();
    std::cout << "✅ 加法测试通过" << std::endl;

    testSubtract();
    std::cout << "✅ 减法测试通过" << std::endl;

    testMultiply();
    std::cout << "✅ 乘法测试通过" << std::endl;

    testDivide();
    std::cout << "✅ 除法测试通过" << std::endl;

    testSquare();
    std::cout << "✅ 平方测试通过" << std::endl;

    testSquareRoot();
    std::cout << "✅ 平方根测试通过" << std::endl;

    std::cout << "\n所有测试通过！" << std::endl;
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "测试失败: " << e.what() << std::endl;
    return 1;
  }
}