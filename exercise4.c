#include <stdio.h>
#include <omp.h>

int main() {
    long long n = 1000000;
    long long sum_reduction = 0;
    long long sum_atomic = 0;
    long long sum_critical = 0;
    long long expected = (n * (n + 1)) / 2;

    // Task 1: Reduction implementation
    #pragma omp parallel for reduction(+:sum_reduction)
    for (long long i = 1; i <= n; i++) {
        sum_reduction += i;
    }

    // Task 1: Atomic implementation
    #pragma omp parallel for
    for (long long i = 1; i <= n; i++) {
        #pragma omp atomic
        sum_atomic += i;
    }

    // Task 1: Critical implementation
    #pragma omp parallel for
    for (long long i = 1; i <= n; i++) {
        #pragma omp critical
        {
            sum_critical += i;
        }
    }

    // Task 3: Sum of squares reduction
    long long n_sq = 1000;
    long long sum_sq = 0;
    long long expected_sq = (n_sq * (n_sq + 1) * (2 * n_sq + 1)) / 6;

    #pragma omp parallel for reduction(+:sum_sq)
    for (long long i = 1; i <= n_sq; i++) {
        sum_sq += i * i;
    }

    printf("Reduction Sum : %lld (Expected: %lld)\n", sum_reduction, expected);
    printf("Atomic Sum    : %lld (Expected: %lld)\n", sum_atomic, expected);
    printf("Critical Sum  : %lld (Expected: %lld)\n", sum_critical, expected);
    printf("Sum of Squares: %lld (Expected: %lld)\n", sum_sq, expected_sq);

    return 0;
}

