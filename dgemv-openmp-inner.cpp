#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

void my_dgemv(int n, double* A, double* x, double* y) {

   #pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      printf("Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
   }

   for (int i = 0; i < n; i++) {
        
        y[i] += A[i * n] * x[0]; // First element of y[i]

		#pragma omp parallel for reduction(+: y[i]) //inner loop
        for (int j = 1; j < n; j++) {
           // #pragma omp atomic prevents thread issues 
            y[i] += A[i * n + j] * x[j]; // Remaining elements of y[i]
        }
    }
}