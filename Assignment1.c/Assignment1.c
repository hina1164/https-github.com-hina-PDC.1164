#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500  // Matrix size

void multiplySequential(int A[N][N], int B[N][N], int C[N][N]) {
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

    clock_t start = clock();
    multiplySequential(A, B, C);
    clock_t end = clock();

    printf("Sequential Execution Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printMatrix(C);

    return 0;
}

