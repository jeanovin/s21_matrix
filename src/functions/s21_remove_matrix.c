/**
 * @brief Удаляет и очищает матрицу, освобождая выделенную память.
 *
 * @param[in] A Указатель на матрицу, которую необходимо удалить.
 */
#include "../s21_matrix.h"

// void s21_remove_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     free(A->matrix[i]);
//   }
//   free(A->matrix);
// }

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}