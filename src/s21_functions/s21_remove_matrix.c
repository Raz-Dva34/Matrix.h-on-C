#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!A) return;  // Ранний возврат, если A равно NULL
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
  memset(A, 0, sizeof(matrix_t));  // Обнуляем структуру
}