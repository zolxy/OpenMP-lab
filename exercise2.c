#include <stdio.h>
#include <omp.h>

int main() {
    int base = 10;
    int scratch = -1;

    // Task 4: Explicit scoping using default(none)
    // Task 2: Using firstprivate so thread-local scratch receives the initial value (-1)
    #pragma omp parallel default(none) firstprivate(base) firstprivate(scratch)
    {
        int tid = omp_get_thread_num();

        #pragma omp critical
        {
            // Task 2: Verify each thread starts with initial scratch value (-1)
            printf("Thread %d initial scratch = %d\n", tid, scratch);
        }

        // Local modifications per thread
        scratch = tid * tid;
        base = 10 + tid;

        #pragma omp critical
        {
            printf("Thread %d: base = %d, scratch = %d\n", tid, base, scratch);
        }
    }

    // Task 1: Verify outer scope base and scratch remain unmodified
    printf("Outside region: base=%d, scratch=%d\n", base, scratch);
    return 0;
}

