#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    error = 1;
  } else {
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix == NULL) error = 1;
  }
  if (error == 0) {
    for (int i = 0; i < rows && error == 0; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
      if (result->matrix[i] == NULL) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
        error = 1;
      }
    }
    result->rows = rows;
    result->columns = columns;
  }
  return error;
}