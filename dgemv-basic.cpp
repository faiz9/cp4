const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
   void my_dgemv(int n, double* A, double* x, double* y) {
/* Pseudocode Taken from Dr. Bethel's lecture slides x, y are vectors of length N.
 * a is nxn, for i=1:n
 * for j=1:n
 * y[i]=y[i]+A[i,j]*x[j];
 */
  for (int i = 0; i < n; i++) {
      // y[i] += A[i*n] * x[0];   this line has errors row-major
        for (int j = 1; j < n; j++) {
            y[i] += A[i*n + j] * x[j]; //accesses i, j
        }
    }
  // return y; does not work function type void.

}
