#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 500  // Matrix size

void multiplyParallelStatic(int A[N][N], int B[N][N], int C[N][N], int num_threads) {
    #pragma omp parallel for num_threads(num_threads) collapse(2) schedule(static)
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

int main() {
    static int A[N][N], B[N][N], C[N][N];

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    int num_threads = 4;
    double start = omp_get_wtime();
    multiplyParallelStatic(A, B, C, num_threads);
    double end = omp_get_wtime();

    printf("Parallel Execution Time (Static Scheduling, %d threads): %f seconds\n", num_threads, end - start);
    printMatrix(C);

    return 0;
}
