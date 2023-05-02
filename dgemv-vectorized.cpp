#include <stdlib.h>
#include <string.h>
#include <cblas.h> //include header file

const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   double alpha = 1.0, beta = 1.0;
    int lda = n, incx = 1, incy = 1;

    // Clear y vector
    memset(y, 0, n * sizeof(double));

    // Loop unrolling by 2
    for (int i = 0; i < n; i += 2) {
        double sum1 = 0.0, sum2 = 0.0;

        for (int j = 0; j < n; j++) {
            sum1 += A[i * n + j] * x[j];
            sum2 += A[(i + 1) * n + j] * x[j];
        }

        y[i] += sum1;
        y[i + 1] += sum2;
    }
}
