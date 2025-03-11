#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 500  // Matrix size

void multiplyParallelDynamic(int A[N][N], int B[N][N], int C[N][N], int num_threads) {
    #pragma omp parallel for num_threads(num_threads) collapse(2) schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int C[N][N]) {
    for (int i = 0; i < 5; i++) {  // Print only first 5 rows for clarity
        for (int j = 0; j < 5; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}