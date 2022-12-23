/*INF1029 - INT ARQUITETURA COMPUTADORES - 2022.2 - 3WA
Trabalho 1 - Implementação do algoritmo otimizado para o produto de matrizes
Nome: Eric Leão     Matrícula: 2110694
Nome: Pedro Machado Peçanha    Matrícula: 2110535*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct matrix {
  unsigned long int height;
  unsigned long int width;
  float *rows;
};

int scalar_matrix_mult(float scalar_value, struct matrix *matrix) {
  if (matrix == NULL)
    return 0;
  int matrixSize = (matrix->height) * (matrix->width);
  while (matrixSize) {
    matrixSize--;
    *(matrix->rows + matrixSize) *= scalar_value;
  }
  return 1;
}

int matrix_matrix_mult(struct matrix *matrixA, struct matrix *matrixB,
                       struct matrix *matrixC) {
  if (matrixA == NULL)
    return 0;                          // matrx A diferente de NULL
  if (matrixB == NULL)
    return 0;                           // matrx B diferente de NULL
  if (matrixC == NULL)
    return 0;                           // matrx C diferente de NULL
  if (matrixA->width != matrixB->height)
    return 0; // matrx A precisa ter largura igual à altura da matrix B
  if (matrixA->height != matrixC->height || matrixB->width != matrixC->width)
    return 0; //matriz C tem que ter altura e largura compativeis com a amatriz A e B
  for (int i = 0; i < matrixA->height; i++) {
    for (int j = 0; j < matrixA->width; j++) {
      for (int k = 0; k < matrixB->width; k++) {
        if (j == 0) { // testa se esta passando pela primeira vez no elemento da
                      // matrix
          if (*(matrixC->rows + i * matrixC->width + k) !=
              0) { // testa se o elemento está zerado
            *(matrixC->rows + i * matrixC->width + k) =
                0; // zera, caso nao esteja zerado
          }
        }
        *(matrixC->rows + i * matrixC->width + k) +=
            *(matrixA->rows + i * matrixA->width + j) *
            *(matrixB->rows + j * matrixB->width + k);
      }
    }
  }
  return 1;
}
