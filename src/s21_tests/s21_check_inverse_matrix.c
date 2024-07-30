#include "../s21_tests.h"

START_TEST(s21_inverse_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_inverse_matrix(&A, &Z);
  s21_remove_matrix(&Z);
  s21_remove_matrix(&A);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  int res;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  res = s21_inverse_matrix(&A, &Z);

  ck_assert_int_eq(Z.matrix[0][0], 1);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_remove_matrix(&A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;
  s21_inverse_matrix(&A, &Z);
  s21_create_matrix(3, 3, &X);
  X.matrix[0][0] = -3.0 / 5.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 1.0 / 5.0;
  X.matrix[1][0] = -4.0 / 5.0;
  X.matrix[1][1] = 1.0;
  X.matrix[1][2] = -2.0 / 5.0;
  X.matrix[2][0] = 16.0 / 15.0;
  X.matrix[2][1] = -2.0 / 3.0;
  X.matrix[2][2] = 1.0 / 5.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s = suite_create("s21_inverse_matrix");  // создает набор кейсов с
  // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_4);
  tcase_add_test(tc1_1, s21_inverse_matrix_5);
  tcase_add_test(tc1_1, s21_inverse_matrix_6);
  suite_add_tcase(s, tc1_1);
  return s;
}