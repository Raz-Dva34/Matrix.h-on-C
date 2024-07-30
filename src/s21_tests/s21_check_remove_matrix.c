#include "../s21_tests.h"

START_TEST(s21_remove_matrix_1) {
  int res = 0;
  matrix_t A;
  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  int res = 0;
  matrix_t A;
  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  int res = 0;
  matrix_t A;
  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  int res = 0;
  matrix_t A;
  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  int res = 0;
  matrix_t A;
  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("s21_remove_matrix");  // создает набор кейсов с
  // заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_remove_matrix_1);
  tcase_add_test(tc1_1, s21_remove_matrix_2);
  tcase_add_test(tc1_1, s21_remove_matrix_3);
  tcase_add_test(tc1_1, s21_remove_matrix_4);
  tcase_add_test(tc1_1, s21_remove_matrix_5);
  suite_add_tcase(s, tc1_1);
  return s;
}