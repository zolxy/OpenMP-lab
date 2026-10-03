#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500

double A[N][N], B[N][N], C[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    double start_time = omp_get_wtime();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    double end_time = omp_get_wtime();

    int num_threads = omp_get_max_threads();
    printf("Matrix Multiplication (%dx%d) using %2d threads: %f seconds\n", N, N, num_threads, end_time - start_time);

    return 0;
}

