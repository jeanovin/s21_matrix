/**
 * @brief Умножает две одинаковые по столбцам и строкам матрицы А и В и
 * сохраняет результат.
 *
 * @param[in] A Указатель на первую матрицу.
 * @param[in] B Указатель на вторую матрицу.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 * @return `0` - успех, `2` - количество столбцов первой матрицы не совпадает с
 * количеством строк второй матрицы.
 */
#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (status == 0) {
    if (B->rows == A->columns) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      status = 2;
    }
  }
  return status;
}