//included libs to fix errors; malloc, memset, memcpy & free
#include <stdlib.h>
#include <string.h>

const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";
/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {

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
}
