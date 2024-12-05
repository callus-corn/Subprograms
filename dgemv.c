#include "blas.h"

void dgemv_(char *trans, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy) {
    int i, j;

    for(i = 0; i < *m; i++){
        for(j = 0; j < *n; j++) {
            y[i] += a[j * *lda + i] * x[i];
        }
    }
}
