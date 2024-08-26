/**
 * @brief Вычисляет определитель квадратной матрицы А и сохраняет результат.
 *
 * @param[in] A Указатель на входную квадратную матрицу.
 * @param[out] result Указатель на переменную, в которую будет сохранен
 * результат.
 * @return `0` - успех, `2` - входная матрица не квадратная.
 */
#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = 0;
  if (status == 0) {
    if (A->rows == A->columns) {
      *result = s21_get_determinant(A);
    } else {
      status = 2;
    }
  }
  return status;
}

/**
 * @brief Рекурсивно вычисляет определитель квадратной матрицы А методом
 * разложения по строке.
 *
 * @param[in] A Указатель на входную квадратную матрицу.
 * @return double Значение определителя матрицы.
 */
double s21_get_determinant(matrix_t *A) {
  double status = 0;
  if (A->rows == 1) {
    status = A->matrix[0][0];
  } else {
    matrix_t tmp;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_get_calc(0, i, A, &tmp);
      if (i % 2) {
        status -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        status += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return status;
}
