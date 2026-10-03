#include <stdio.h>
#include <omp.h>

void perform_task_A() {
    printf("Task A executed by Thread %d\n", omp_get_thread_num());
}

void perform_task_B() {
    printf("Task B executed by Thread %d\n", omp_get_thread_num());
}

void perform_task_C() {
    printf("Task C executed by Thread %d\n", omp_get_thread_num());
}

int main() {
    #pragma omp parallel num_threads(3)
    {
        #pragma omp sections
        {
            #pragma omp section
            perform_task_A();

            #pragma omp section
            perform_task_B();

            #pragma omp section
            perform_task_C();
        }
    }
    return 0;
}

