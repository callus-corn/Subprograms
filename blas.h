#ifndef __BLAS_H__
#define __BLAS_H__

double ddot_(int *n, double *dx, int *incx, double *dy, int *incy);
void dgemv_(char *trans, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, double *a, int *lda, double *b, int *ldb, double *beta, double *c, int *ldc);

#endif // __BLAS_H__
