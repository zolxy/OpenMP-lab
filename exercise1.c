#include <stdio.h>
#include <omp.h>

int main() {
    // Task 3: Sequential print before parallel region
    printf("Before parallel region (Executes 1 time by sequential thread)\n");

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        #pragma omp critical
        {
            // Task 1 & Task 2: Thread greeting and team size
            printf("Hello World from thread %d out of %d threads!\n", tid, num_threads);
        }
    }

    // Task 3 & Task 4: Print statement after implicit barrier
    printf("After parallel region (Executes 1 time after implicit barrier synchronization)\n");
    return 0;
}

