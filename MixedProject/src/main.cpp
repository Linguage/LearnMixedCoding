#include "fortran_interface.h" // 将用于调用 Fortran 子程序
#include <iostream>

int main() {
  std::cout << "Hello from C++!" << std::endl;
  int a = 5;
  int b = 10;
  int result = 0;
  // 调用 Fortran 子程序
  add_integers_fortran(&a, &b, &result);
  std::cout << "Fortran calculated: " << a << " + " << b << " = " << result
            << std::endl;
  return 0;
}
