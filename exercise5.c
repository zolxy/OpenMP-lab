#include <stdio.h>
#include <omp.h>

int main() {
    long global_counter = 0;
    long iterations = 100000;

    #pragma omp parallel for num_threads(4)
    for (long i = 0; i < iterations; i++) {
        #pragma omp critical
        {
            global_counter++;
        }
    }

    printf("Final Counter Value = %ld (Expected: %ld)\n", global_counter, iterations);
    return 0;
}

