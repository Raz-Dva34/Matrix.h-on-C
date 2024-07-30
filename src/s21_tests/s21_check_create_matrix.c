#include "../s21_tests.h"

START_TEST(s21_create_matrix_1) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(2, 4, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  int res = 0;
  matrix_t A = {0};
  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s = suite_create("s21_create_matrix");  // создает набор кейсов с
  // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_create_matrix_4);
  tcase_add_test(tc1_1, s21_create_matrix_5);
  tcase_add_test(tc1_1, s21_create_matrix_6);
  tcase_add_test(tc1_1, s21_create_matrix_7);
  tcase_add_test(tc1_1, s21_create_matrix_8);
  tcase_add_test(tc1_1, s21_create_matrix_9);
  suite_add_tcase(s, tc1_1);
  return s;
}