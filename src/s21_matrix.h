#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H
#define SUCCESS 1
#define FAILURE 0

#include <stdlib.h>
#include <string.h>

#include "math.h"
#include "stdio.h"

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// dop_func
void s21_create_minor(const matrix_t *A, matrix_t *result, int row, int column);
double s21_for_function_determin(const matrix_t *A);
int s21_check_matrix_validity(matrix_t *A);

#endif  // SRC_S21_MATRIX