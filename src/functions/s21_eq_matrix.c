/**
 * @brief Сравнивает матрицы А и В на равенство с точностью до `0.0000001`.
 *
 * @param[in] A Указатель на первую матрицу.
 * @param[in] B Указатель на вторую матрицу.
 * @return `1` - матрицы равны, `0` - матрицы не равны.
 */
#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;
  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
          status = 0;
          break;
        }
      }
    }

  } else {
    status = 0;
  }
  return status;
}