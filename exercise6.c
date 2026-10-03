#include <stdio.h>
#include <omp.h>

long fib(int n) {
    long x, y;
    if (n < 2) return n;

    #pragma omp task shared(x) firstprivate(n)
    x = fib(n - 1);

    #pragma omp task shared(y) firstprivate(n)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}

int main() {
    int n = 20;
    long result;

    double start_time = omp_get_wtime();

    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        {
            result = fib(n);
        }
    }

    double end_time = omp_get_wtime();

    printf("Fibonacci(%d) = %ld\n", n, result);
    printf("Time taken   = %f seconds\n", end_time - start_time);
    return 0;
}

