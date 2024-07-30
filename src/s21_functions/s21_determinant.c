#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;  // Инициализация кода ошибки (0 - нет ошибок)
  if (s21_check_matrix_validity(A) != 0) {
    error = 1;  // Ошибка: некорректная матрица
  } else if (A->rows != A->columns) {
    error = 2;  // Ошибка: размеры не совпадают
  } else {
    *result = s21_for_function_determin(A);  // Вычисление определителя
  }
  return error;  // Возврат кода ошибки (или 0, если нет ошибок)
}
