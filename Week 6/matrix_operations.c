#include <stdio.h>
#include "matrix_operations.h"


void matmult(double A[N][P], double B[P][Q], double C[N][Q]) {
    // declare loop indices
    int i,j,k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < Q; j++) {
            for (k = 0; k < P; k++) {
                
                // multiply each corresponding elements in A B.
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}