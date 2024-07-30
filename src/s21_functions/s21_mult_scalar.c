#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = s21_check_matrix_validity(A);
  if (error == 0) {
    error = s21_create_matrix(A->rows, A->columns, result);
  }
  if (error == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;  // Возвращаем флаг ошибки (0, если успешно, 1 в случае ошибки)
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = s21_check_matrix_validity(A) || s21_check_matrix_validity(B);
  if (!error) {
    error = (A->columns != B->rows)
                ? 2
                : s21_create_matrix(A->rows, B->columns, result);
  }
  if (!error) {
    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < B->columns; k++) {
        result->matrix[i][k] = 0;
      }
    }
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        for (int q = 0; q < B->columns; q++) {
          result->matrix[i][q] += A->matrix[i][j] * B->matrix[j][q];
        }
      }
    }
  }
  return error;
}
