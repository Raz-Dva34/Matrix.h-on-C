#include "../s21_tests.h"

START_TEST(s21_transpose_1) {
  int res = 0;
  matrix_t A = {0};
  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t T = {0};
  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 3, &B);
  s21_init_matrix(1.0, &B);
  s21_transpose(&A, &T);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&T);
}
END_TEST

START_TEST(s21_transpose_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;
  res = s21_transpose(&A, &T);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s = suite_create("s21_transpose");  // создает набор кейсов с
  // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_transpose_1);
  tcase_add_test(tc1_1, s21_transpose_2);
  tcase_add_test(tc1_1, s21_transpose_3);
  suite_add_tcase(s, tc1_1);
  return s;
}