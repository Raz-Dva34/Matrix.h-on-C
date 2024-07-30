#include "../s21_matrix.h"

int s21_check_matrix_validity(matrix_t *A) {
  return (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) ? 1 : 0;
}

void s21_create_minor(const matrix_t *A, matrix_t *result, int row,
                      int column) {
  int create_minor =
      0;  // Флаг для определения, нужно ли создавать матрицу минора
  int flag_minor = 0;  // Флаг, определяющий, можно ли вставлять элемент в минор
  if (A->rows == 1) {
    s21_create_matrix(A->rows, 1, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    s21_create_matrix(A->rows - 1, A->columns - 1, result);
    create_minor = 1;
  }
  for (int i = 0; i < A->rows && create_minor == 1; i++) {
    for (int j = 0; j < A->columns; j++) {
      flag_minor = 0;
      if (i != row) {
        flag_minor = 1;
      }
      if (j == column) {
        flag_minor = 0;
      }
      if (flag_minor == 1) {
        int ii = i, jj = j;
        if (i > row) ii--;
        if (j > column) jj--;
        result->matrix[ii][jj] = A->matrix[i][j];
      }
    }
  }
}

double s21_for_function_determin(const matrix_t *A) {
  int sign = 1;  // Знак для вычисления детерминанта
  double result = 0;  // Результат вычисления детерминанта
  int rows = A->rows;
  int columns = A->columns;

  if (rows == 1) {
    result = A->matrix[0][0];  // Базовый случай для матрицы 1x1
  } else if (rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    // Базовый случай для матрицы 2x2
  } else {
    // Вычисление детерминанта через разложение по первой строке
    for (int j = 0; j < columns; j++, sign *= -1) {
      matrix_t minor = {0};               // Матрица минора
      s21_create_minor(A, &minor, 0, j);  // Создание минора
      double minor_determinant = s21_for_function_determin(&minor);
      result += sign * A->matrix[0][j] * minor_determinant;
      // Рекурсивный вызов для минора и вычисление суммы
      s21_remove_matrix(&minor);  // Удаление минора после использования
    }
  }
  return result;  // Возвращаем результат после всех вычислений
}
