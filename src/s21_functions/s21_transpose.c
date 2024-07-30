#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (s21_check_matrix_validity(A) != 0 ||
      s21_create_matrix(A->columns, A->rows, result) != 0) {
    error = 1;
  }
  if (error == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];  // Транспонирование
      }
    }
  }
  return error;  // Вернуть флаг ошибки (0, если успешно, 1 в случае ошибки)
}