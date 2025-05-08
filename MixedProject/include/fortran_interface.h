#ifndef FORTRAN_INTERFACE_H
#define FORTRAN_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

// 声明 Fortran 子程序
// 注意：Fortran 编译器通常会将子程序名称转换为小写并可能添加下划线
// 具体取决于编译器和调用约定。gfortran 通常是小写加下划线。
void add_integers_fortran_(int *a, int *b, int *result);

#ifdef __cplusplus
}
#endif

// C++ 包装函数，隐藏下划线等细节
static inline void add_integers_fortran(int *a, int *b, int *result) {
  add_integers_fortran_(a, b, result);
}

#endif // FORTRAN_INTERFACE_H
