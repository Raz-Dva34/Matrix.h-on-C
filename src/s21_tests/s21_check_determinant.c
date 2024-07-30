#include "../s21_tests.h"

START_TEST(s21_determinant_1) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("s21_determinant");  // создает набор кейсов
  // с заданным именем
  TCase *tc1_1 = tcase_create("case_is_equal");
  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);
  tcase_add_test(tc1_1, s21_determinant_4);
  tcase_add_test(tc1_1, s21_determinant_5);
  tcase_add_test(tc1_1, s21_determinant_6);
  suite_add_tcase(s, tc1_1);
  return s;
}