#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (s21_check_matrix_validity(A) != 0) {
    error = 1;  // Ошибка валидности матрицы
  } else {
    double opred;
    error = s21_determinant(A, &opred);
    if (error == 0) {
      if (opred == 0) {
        error = 2;  // Определитель равен 0, обратной матрицы нет
      } else {
        matrix_t minor = {0};
        matrix_t transpon_matr = {0};
        if ((error = s21_calc_complements(A, &minor)) == 0) {
          s21_transpose(&minor, &transpon_matr);
          error = s21_mult_number(&transpon_matr, 1 / opred, result);
          s21_remove_matrix(&transpon_matr);
        }
        s21_remove_matrix(&minor);
      }
    }
  }
  return error;
}
