#include "calculator.h"
#include <cmath>
#include <stdexcept>

Calculator::Calculator() {
  // 构造函数实现
}

Calculator::~Calculator() {
  // 析构函数实现
}

double Calculator::add(double a, double b) const { return a + b; }

double Calculator::subtract(double a, double b) const { return a - b; }

double Calculator::multiply(double a, double b) const { return a * b; }

double Calculator::divide(double a, double b) const {
  if (!checkDivideByZero(b)) {
    throw std::invalid_argument("除数不能为零");
  }
  return a / b;
}

double Calculator::square(double x) const { return x * x; }

double Calculator::squareRoot(double x) const {
  if (x < 0) {
    throw std::domain_error("不能对负数进行开平方运算");
  }
  return std::sqrt(x);
}

double Calculator::power(double base, double exponent) const {
  return std::pow(base, exponent);
}

bool Calculator::checkDivideByZero(double divisor) const {
  // 检查除数是否为零（考虑浮点精度）
  const double epsilon = 1e-10;
  return std::abs(divisor) > epsilon;
}