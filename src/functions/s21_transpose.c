/**
 * @brief Выполняет транспонирование матрицы (замена местами её строк и
 * столбцов) `A` и сохраняет результат в новой матрице.
 *
 * @param[in] A Указатель на входную матрицу.
 * @param[out] result Указатель на результат.
 * @return `0` - успех.
 */
#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (status == 0) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return status;
}

//

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}