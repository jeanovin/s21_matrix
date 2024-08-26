/**
 * @brief Создаёт матрицу заданного размера `rows` x `columns` и сохраняет её.
 *
 * @param[in] rows Количество строк матрицы.
 * @param[in] columns Количество столбцов матрицы.
 * @param[out] result Указатель на структуру matrix_t, в которую будет сохранена
 * созданная матрица.
 * @return `0` - успех, `1` - ошибка (не удалось выделить память или
 * некорректные размеры).
 */
#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 1;
  result->matrix = NULL;
  if (rows > 0 && columns > 0) {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      status = 0;
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    }
    result->rows = rows;
    result->columns = columns;
  }
  return status;
}
