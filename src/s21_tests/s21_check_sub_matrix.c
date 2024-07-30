#include "../s21_tests.h"

START_TEST(s21_sub_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[1][2] = 0.0;
  X.matrix[1][3] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[2][2] = 0.0;
  X.matrix[2][3] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;
  X.matrix[3][2] = 0.0;
  X.matrix[3][3] = 0.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(0.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(2.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = -2.0;
  X.matrix[0][1] = -2.0;
  X.matrix[0][2] = -2.0;
  X.matrix[0][3] = -2.0;
  X.matrix[1][0] = -2.0;
  X.matrix[1][1] = -2.0;
  X.matrix[1][2] = -2.0;
  X.matrix[1][3] = -2.0;
  X.matrix[2][0] = -2.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -2.0;
  X.matrix[2][3] = -2.0;
  X.matrix[3][0] = -2.0;
  X.matrix[3][1] = -2.0;
  X.matrix[3][2] = -2.0;
  X.matrix[3][3] = -2.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-3.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(5.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = -8.0;
  X.matrix[0][1] = -8.0;
  X.matrix[0][2] = -8.0;
  X.matrix[0][3] = -8.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -8.0;
  X.matrix[1][2] = -8.0;
  X.matrix[1][3] = -8.0;
  X.matrix[2][0] = -8.0;
  X.matrix[2][1] = -8.0;
  X.matrix[2][2] = -8.0;
  X.matrix[2][3] = -8.0;
  X.matrix[3][0] = -8.0;
  X.matrix[3][1] = -8.0;
  X.matrix[3][2] = -8.0;
  X.matrix[3][3] = -8.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  s21_init_matrix(5.0, &A);
  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-3.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 8.0;
  X.matrix[0][1] = 8.0;
  X.matrix[0][2] = 8.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 8.0;
  X.matrix[1][2] = 8.0;
  X.matrix[1][3] = 8.0;
  X.matrix[2][0] = 8.0;
  X.matrix[2][1] = 8.0;
  X.matrix[2][2] = 8.0;
  X.matrix[2][3] = 8.0;
  X.matrix[3][0] = 8.0;
  X.matrix[3][1] = 8.0;
  X.matrix[3][2] = 8.0;
  X.matrix[3][3] = 8.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(4, 2, &B);
  s21_init_matrix(1.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);
  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -4.0;
  X.matrix[1][0] = -4.0;
  X.matrix[1][1] = -4.0;
  X.matrix[2][0] = -4.0;
  X.matrix[2][1] = -4.0;
  X.matrix[3][0] = -4.0;
  X.matrix[3][1] = -4.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 2, &A);
  s21_init_matrix(4.0, &A);
  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);
  s21_sub_matrix(&A, &B, &Z);
  s21_create_matrix(4, 2, &X);
  X.matrix[0][0] = 6.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 6.0;
  X.matrix[2][0] = 6.0;
  X.matrix[2][1] = 6.0;
  X.matrix[3][0] = 6.0;
  X.matrix[3][1] = 6.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_sub_matrix_8) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(4, 3, &B);
  res = s21_sub_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_sub_matrix_9) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(-4, 3, &B);
  res = s21_sub_matrix(&A, &B, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *s = suite_create("s21_sub_matrix");  // создает набор кейсов
  // с заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_sub_matrix_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_3);
  tcase_add_test(tc1_1, s21_sub_matrix_4);
  tcase_add_test(tc1_1, s21_sub_matrix_5);
  tcase_add_test(tc1_1, s21_sub_matrix_6);
  tcase_add_test(tc1_1, s21_sub_matrix_7);
  tcase_add_test(tc1_1, s21_sub_matrix_8);
  tcase_add_test(tc1_1, s21_sub_matrix_9);
  suite_add_tcase(s, tc1_1);
  return s;
}