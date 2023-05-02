#include <stdlib.h>
#include <string.h>
#include <cblas.h>
#include <immintrin.h>

const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";


/* void my_dgemv(int n, double* A, double* x, double* y) {
    // insert your code here: implementation of vectorized vector-matrix multiply
    double* tmp = (double*) malloc(n * sizeof(double)); // allocate temporary array
    memset(tmp, 0, n * sizeof(double)); // initialize temporary array to zero
    // Outer loop: iterate over rows of A
    for (int i = 0; i < n; i++) {
        // Inner loop: iterate over columns of A and x
        for (int j = 0; j < n; j++) {
            tmp[i] += A[i*n + j] * x[j]; // accumulate intermediate results into tmp
        }
    }
    // Copy temporary array into y
    memcpy(y, tmp, n * sizeof(double));
    free(tmp); // free temporary array
} */

//Vectorization Analogy: Loop Unrolling April 18th
void my_dgemv(int n, double* A, double* x, double* y) {
  for (int i = 0; i < n; i++) {
        double temp = 0.0;

        // Vectorized inner loop
        for (int j = 0; j < n; j += 4) {
            temp += A[i * n + j] * x[j];
            temp += A[i * n + j + 1] * x[j + 1];
            temp += A[i * n + j + 2] * x[j + 2];
            temp += A[i * n + j + 3] * x[j + 3];
        }

        // Handle remaining elements (if n is not divisible by 4)
        for (int j = n - (n % 4); j < n; j++) {
            temp += A[i * n + j] * x[j];
        }

        y[i] += temp;
    }
}
