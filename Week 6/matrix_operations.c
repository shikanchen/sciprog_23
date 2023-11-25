#include <stdio.h>
#include "matrix_operations.h"


void matmult(double A[N][P], double B[P][Q], double C[N][Q]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            for (int k = 0; k < P; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}