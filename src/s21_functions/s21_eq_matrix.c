#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;  // Инициализация результата сравнения
  if (s21_check_matrix_validity(A) == 0 && s21_check_matrix_validity(B) == 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
            result = FAILURE;  // Если хотя бы один элемент различается,
            // установить результат в FAILURE
            break;
          }
        }
        if (result == FAILURE) {
          break;
        }
      }
    } else {
      result = FAILURE;  // Если размерности матриц различаются, установить
                         // результат в FAILURE
    }
  } else {
    result = FAILURE;  // Если есть ошибки в функциях s21_matrix_looking_for,
    // установить результат в FAILURE
  }
  return result;  // Вернуть результат сравнения (SUCCESS, если матрицы равны,
                  // иначе FAILURE)
}