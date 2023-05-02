const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

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
