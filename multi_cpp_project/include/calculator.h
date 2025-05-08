#pragma once

/**
 * @brief 简单的计算器类，提供基本和高级数学运算
 */
class Calculator {
public:
  Calculator();
  ~Calculator();

  // 基本运算
  double add(double a, double b) const;
  double subtract(double a, double b) const;
  double multiply(double a, double b) const;
  double divide(double a, double b) const;

  // 高级运算
  double square(double x) const;
  double squareRoot(double x) const;
  double power(double base, double exponent) const;

private:
  // 内部实现细节
  bool checkDivideByZero(double divisor) const;
};