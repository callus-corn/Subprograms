#include "blas.h"

double ddot_(int *n, double *dx, int *incx, double *dy, int *incy) {
  int i;
  double ddot = 0;

  for (i = 0; i < *n; i++){
    ddot += dx[i] * dy[i];
  }

  return ddot;
}
