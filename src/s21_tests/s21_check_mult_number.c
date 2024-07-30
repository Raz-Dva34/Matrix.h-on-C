#include "../s21_tests.h"
START_TEST(s21_mult_number_1) {
  int res = 0;
  double number = 3.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_mult_number(&A, number, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 3.0;
  X.matrix[0][1] = 6.0;
  X.matrix[0][2] = 9.0;
  X.matrix[0][3] = 12.0;
  X.matrix[1][0] = 15.0;
  X.matrix[1][1] = 18.0;
  X.matrix[1][2] = 21.0;
  X.matrix[1][3] = 24.0;
  X.matrix[2][0] = 27.0;
  X.matrix[2][1] = 30.0;
  X.matrix[2][2] = 33.0;
  X.matrix[2][3] = 36.0;
  X.matrix[3][0] = 39.0;
  X.matrix[3][1] = 42.0;
  X.matrix[3][2] = 45.0;
  X.matrix[3][3] = 48.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_2) {
  int res = 0;
  double number = 5.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_mult_number(&A, number, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 5.0;
  X.matrix[0][1] = 10.0;
  X.matrix[0][2] = 15.0;
  X.matrix[0][3] = 20.0;
  X.matrix[1][0] = 25.0;
  X.matrix[1][1] = 30.0;
  X.matrix[1][2] = 35.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 45.0;
  X.matrix[2][1] = 50.0;
  X.matrix[2][2] = 55.0;
  X.matrix[2][3] = 60.0;
  X.matrix[3][0] = 65.0;
  X.matrix[3][1] = 70.0;
  X.matrix[3][2] = 75.0;
  X.matrix[3][3] = 80.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_3) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);
  s21_mult_number(&A, number, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = 4.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 10.0;
  X.matrix[2][0] = 12.0;
  X.matrix[2][1] = 14.0;
  X.matrix[3][0] = 16.0;
  X.matrix[3][1] = 18.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_4) {
  int res = 0;
  double number = -2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);
  s21_mult_number(&A, number, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -6.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -10.0;
  X.matrix[2][0] = -12.0;
  X.matrix[2][1] = -14.0;
  X.matrix[3][0] = -16.0;
  X.matrix[3][1] = -18.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_5) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(2.0, &A);
  s21_mult_number(&A, number, &Z);
  s21_create_matrix(1, 1, &X);
  X.matrix[0][0] = 4.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_6) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(0, 0, &A);
  res = s21_mult_number(&A, number, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_mult_number_1);
  tcase_add_test(tc1_1, s21_mult_number_2);
  tcase_add_test(tc1_1, s21_mult_number_3);
  tcase_add_test(tc1_1, s21_mult_number_4);
  tcase_add_test(tc1_1, s21_mult_number_5);
  tcase_add_test(tc1_1, s21_mult_number_6);
  suite_add_tcase(s, tc1_1);
  return s;
}