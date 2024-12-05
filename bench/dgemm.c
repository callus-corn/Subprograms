#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "blas.h"

int main(int argc, char *argv[]){

  double *a, *b, *c;
  double alpha = 1.0;
  double beta = 0.0;
  char transa = 'N';
  char transb = 'N';
  int m, n, k, lda, ldb, ldc;

  int from  =   1;
  int to    = 200;
  int step  =   1;
  int loops =   1;

  struct timespec start = { 0, 0 }, stop = { 0, 0 };
  double total_time, average_time;

  int i, l;

  argc--;argv++;

  if (argc > 0) { from  = atol(*argv); argc--; argv++; }
  if (argc > 0) { to    = atol(*argv); argc--; argv++; }
  if (argc > 0) { step  = atol(*argv); argc--; argv++; }
  if (argc > 0) { loops = atol(*argv); argc--; argv++; }


  m = to;
  n = to;
  k = to;

  if (( a = (double *)malloc(sizeof(double) * m * k)) == NULL) {
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  if (( b = (double *)malloc(sizeof(double) * k * n)) == NULL) {
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  if (( c = (double *)malloc(sizeof(double) * m * n)) == NULL) {
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }

  for (i = 0; i < m * k; i++) {
    a[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }
  for (i = 0; i < k * n; i++) {
    b[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }
  for (i = 0; i < m * n; i++) {
    c[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }

  fprintf(stderr, "From : %3d  To : %3d Step=%d : Transa=%c : Transb=%c\n", from, to, step, transa, transb);
  fprintf(stderr, "          SIZE                   Flops             Time\n");

  for (i = from; i <= to; i += step) {
    m = i;
    n = i;
    k = i;

    if (transa == 'N') { lda = m; }
    else { lda = k; }
    if (transb == 'N') { ldb = k; }
    else { ldb = n; }
    ldc = m;

    clock_gettime(CLOCK_REALTIME, &start);
    for (l = 0; l < loops; l++) {
      dgemm_(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
    }
    clock_gettime(CLOCK_REALTIME, &stop);
    total_time = (double)(stop.tv_sec - start.tv_sec) + (double)((stop.tv_nsec - start.tv_nsec)) * 1.e-9;
    average_time = total_time / loops;

    fprintf(stderr, " %6d %6d %6d : %10.2f MFlops %10.6f sec\n", m, n, k, 2. * (double)k * (double)m * (double)n / average_time * 1.e-6, total_time);
  }

  return 0;
}

