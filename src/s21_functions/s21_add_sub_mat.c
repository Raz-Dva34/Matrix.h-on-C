#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = s21_check_matrix_validity(A);
  if (error == 0) {
    error = s21_check_matrix_validity(B);
  }
  if (error == 0) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error = 2;  // Матрицы имеют разные размеры
    }
  }
  if (error == 0 && s21_create_matrix(A->rows, A->columns, result) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return error;  // Возвращаем код ошибки или 0, если успешно
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = s21_check_matrix_validity(A);
  if (error == 0) {
    error = s21_check_matrix_validity(B);
  }
  if (error == 0) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error = 2;  // Матрицы имеют разные размеры
    } else if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      error = 1;  // Ошибка создания матрицы-результата
    }
  } else {
    error = 1;  // Одна или обе матрицы некорректны
  }
  return error;  // Возвращаем код ошибки или 0, если успешно
}
