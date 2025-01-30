#ifndef __BLAS_H__
#define __BLAS_H__

void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, double *a, int *lda, double *b, int *ldb, double *beta, double *c, int *ldc);

#endif // __BLAS_H__
