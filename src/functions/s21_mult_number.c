/**
 * @brief Умножает все элементы матрицы А на заданное число и сохраняет
 * результат в новой матрице.
 *
 * @param[in] A Указатель на входную матрицу.
 * @param[in] number Число, на которое необходимо умножить элементы матрицы.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 * @return `0` - успех.
 */
#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = 0;
  if (status == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status;
}