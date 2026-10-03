#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 3000000

int main() {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));
    double *c = (double *)malloc(N * sizeof(double));
    double alpha = 2.0; // Task 1: alpha = 2.0

    for (int i = 0; i < N; i++) {
        a[i] = (double)i;
        b[i] = 2.0 * i;
    }

    // Task 3: Separate #pragma omp parallel and #pragma omp for directives
    #pragma omp parallel default(none) shared(a, b, c, alpha)
    {
        #pragma omp for schedule(static)
        for (int i = 0; i < N; i++) {
            c[i] = alpha * a[i] + b[i]; // c_i = 2(i) + 2i = 4i
        }
    }

    // Task 2: Validation check against expected value (4.0 * i)
    int errors = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] != 4.0 * i) {
            errors++;
        }
    }

    printf("c[0]=%.1f c[n-1]=%.1f errors=%d\n", c[0], c[N-1], errors);

    free(a); free(b); free(c);
    return 0;
}

