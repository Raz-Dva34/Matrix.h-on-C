#include "s21_tests.h"

void s21_init_matrix(double number, matrix_t *A) {
  int x = 0;
  int y = 0;
  for (x = 0; x < A->rows; x++) {
    for (y = 0; y < A->columns; y++) {
      A->matrix[x][y] = number;
      number++;
    }
  }
}

int main(void) {
  int no_failed = 0;
  Suite *test_all[] = {s21_create_matrix_suite(), s21_eq_matrix_suite(),
                       s21_remove_matrix_suite(), s21_sum_matrix_suite(),
                       s21_sub_matrix_suite(),    s21_mult_number_suite(),
                       s21_mult_matrix_suite(),   s21_transpose_suite(),
                       s21_determinant_suite(),   s21_calc_complements_suite(),
                       s21_inverse_matrix_suite()};

  SRunner *runner;
  runner = srunner_create(test_all[0]);
  srunner_set_fork_status(runner, CK_NOFORK);
  for (size_t i = 1; i < (sizeof((test_all)) / sizeof((test_all)[0])); i++)
    srunner_add_suite(runner, test_all[i]);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}