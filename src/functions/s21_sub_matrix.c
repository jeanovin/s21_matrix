/**
 * @brief Выполняет вычитание одинаковых по столбцам и строкам матрицы В из
 * матрицы А и сохраняет в новой матрице.
 *
 * @param[in] A Указатель на первую матрицу.
 * @param[in] B Указатель на вторую матрицу.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 * @return `0` - успех, `2` - размеры матриц не совпадают.
 */
#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (status == 0) {
    if ((A->columns == B->columns) && (A->rows == B->rows)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      status = 2;
    }
  }
  return status;
}