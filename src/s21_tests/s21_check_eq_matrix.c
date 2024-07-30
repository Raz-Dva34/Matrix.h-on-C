#include "../s21_tests.h"

START_TEST(s21_eq_matrix_1) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_init_matrix(2.0, &B);
  res = s21_eq_matrix(&B, &A);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  s21_init_matrix(-5.0, &A);
  s21_create_matrix(3, 4, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(10.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_init_matrix(-10.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 3, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.11111112, &A);
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.11111118, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(-1.11111112, &A);
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(-1.11111118, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_eq_matrix_9) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.11111112, &A);
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(-1.11111118, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_10) {
  int res = 0;
  matrix_t A = {0}, B;
  A.matrix = 0;
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(-1.11111118, &B);
  res = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_11) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(9, 10, &B);
  s21_init_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_12) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(1, 1, &B);
  s21_init_matrix(2.0, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_eq_matrix_13) {
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.1111112, &A);
  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.1111113, &B);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s = suite_create("s21_eq_matrix");  // создает набор кейсов с
  // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_eq_matrix_4);
  tcase_add_test(tc1_1, s21_eq_matrix_5);
  tcase_add_test(tc1_1, s21_eq_matrix_6);
  tcase_add_test(tc1_1, s21_eq_matrix_7);
  tcase_add_test(tc1_1, s21_eq_matrix_8);
  tcase_add_test(tc1_1, s21_eq_matrix_9);
  tcase_add_test(tc1_1, s21_eq_matrix_10);
  tcase_add_test(tc1_1, s21_eq_matrix_11);
  tcase_add_test(tc1_1, s21_eq_matrix_12);
  tcase_add_test(tc1_1, s21_eq_matrix_13);
  suite_add_tcase(s, tc1_1);
  return s;
}