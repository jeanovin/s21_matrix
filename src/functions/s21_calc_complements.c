/**
 * @brief Вычисляет матрицу алгебраических дополнений для квадратной матрицы А и
 * сохраняет ее.
 *
 * @param[in] A Указатель на входную квадратную матрицу.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 * @return `0` - успех, `2` - входная матрица не квадратная.
 */
#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (status == 0) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t calc;
          double determinant = 0;
          s21_create_matrix(A->columns - 1, A->rows - 1, &calc);
          s21_get_calc(i, j, A, &calc);
          s21_determinant(&calc, &determinant);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant;
          s21_remove_matrix(&calc);
        }
      }
    } else {
      status = 2;
    }
  }
  return status;
}
/**
 * @brief Вычисляет подматрицу, исключив указанную строку и столбец из матрицы А
 * и сохраняет результат.
 *
 * @param[in] row Индекс строки, которую нужно исключить.
 * @param[in] col Индекс столбца, который нужно исключить.
 * @param[in] A Указатель на исходную матрицу.
 * @param[out] result Указатель на матрицу, в которую будет сохранен результат.
 */
void s21_get_calc(int row, int col, matrix_t *A, matrix_t *result) {
  int a_row = 0;
  int a_col;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    a_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[a_row][a_col] = A->matrix[i][j];
      a_col++;
    }
    a_row++;
  }
}