#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  // Функция для вычисления матрицы дополнений для матрицы A
  int error = 0;  // Инициализация кода ошибки (0 - нет ошибок)
  if (s21_check_matrix_validity(A) != 0) {
    error = 1;  // Ошибка: некорректная матрица
  } else if (A->rows != A->columns) {
    error = 2;  // Ошибка: размеры не совпадают
  }
  if (error == 0 && s21_create_matrix(A->rows, A->columns, result) != 0) {
    error = 1;  // Ошибка: не удалось создать матрицу
  }
  if (!error) {
    matrix_t minor = {0};  // Инициализация временной матрицы для минора
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        // Перебор всех элементов в результатирующей матрице
        s21_create_minor(A, &minor, i, j);  // Создание минора матрицы A
        double res = s21_for_function_determin(
            &minor);  // Вычисление определителя минора
        result->matrix[i][j] =
            pow((-1), i + j) *
            res;  // Запись дополнения в результат с учетом знака
        s21_remove_matrix(
            &minor);  // Освобождение памяти, выделенной для минора
      }
    }
  }
  return error;  // Возвращаем код ошибки или 0, если успешно
}
