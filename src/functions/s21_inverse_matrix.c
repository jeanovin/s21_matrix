/**
 * @brief Вычисляет обратную матрицу для заданной квадратной матрицы А и
 * сохраняет ее.
 *
 * @param[in] A Указатель на входную квадратную матрицу.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 * @return`0` - успех, `1` - некорректные размеры или NULL указатель, `2` -
 * матрица не квадратная или её определитель равен нулю.
 */
#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = 0;
  if ((A == NULL && A->matrix == NULL) || (A->rows < 0 && A->columns < 0)) {
    status = 1;
  } else if (A->rows != A->columns) {
    status = 2;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) > 1e-7) {
      matrix_t tempM1, tempM2;
      s21_calc_complements(A, &tempM1);
      s21_transpose(&tempM1, &tempM2);
      s21_remove_matrix(&tempM1);
      s21_mult_number(&tempM2, 1.0 / det, result);
      s21_remove_matrix(&tempM2);
    } else {
      status = 2;
    }
  }
  return status;
}