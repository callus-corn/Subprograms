#include "blas.h"

void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, double *a, int *lda, double *b, int *ldb, double *beta, double *c, int *ldc) {
    int im, in, ik;

    for (im = 0; im < *m; im++) {
        for (in = 0; in < *n; in++) {
            for (ik = 0; ik < *k; ik++) {
                c[in * *ldc + im] += a[ik * *lda + im] * b[in * *ldb + ik];
            }
       }
    }
}
