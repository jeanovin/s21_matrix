/**
 * @file s21_matrix.h
 * @brief В библиотеку входят функции для создания и удаления матриц,
 * выполнения основных операций (сложение, вычитание, умножение),
 * транспонирования, нахождения детерминанта и обратной матрицы,
 * а также проверки равенства матриц.
 * @result Операции должны возвращать результирующий код:
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
void s21_get_calc(int row, int col, matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
double s21_get_determinant(matrix_t *A);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);