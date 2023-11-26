#include <stdio.h>
#include "matrix_operations.h"


int main() {
    
    // declare loop index
    int i,j;
    
    // define matriices A B C
    double A[N][P], B[P][Q], C[N][Q];
    
    // init and print A B C
    printf("Matrix A:\n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            A[i][j] = i + j;
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix B:\n");
    for (i = 0; i < P; i++) {
        for (j = 0; j < Q; j++) {
            B[i][j] = i - j;
            printf("%.2f ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix C (Before multiplication):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < Q; j++) {
            C[i][j] = 0.0;
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }
    
    // multiply matrices C = A x B
    matmult(A, B, C);

    // print result
    printf("\nMatrix C (After multiplication):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < Q; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
