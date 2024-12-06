#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "blas.h"

int main(int argc, char *argv[]){

  double *a, *x, *y;
  double alpha = 1.0;
  double beta = 1.0;
  char trans='N';
  int n, m;
  int inc_x = 1;
  int inc_y = 1;

  int from =   1;
  int to   = 200;
  int step =   1;
  int loops = 1;

  struct timespec start = { 0, 0 }, stop = { 0, 0 };
  double total_time, average_time;

  int i, j, l;

  argc--;argv++;

  if (argc > 0) { from     = atol(*argv);	argc--; argv++;}
  if (argc > 0) { to       = atol(*argv);	argc--; argv++;}
  if (argc > 0) { step     = atol(*argv);	argc--; argv++;}
  if (argc > 0) { loops    = atol(*argv);	argc--; argv++;}
  if (argc > 0) { trans    = **argv;		argc--; argv++;}

  if (( a = (double *)malloc(sizeof(double) * to * to)) == NULL){
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  if (( x = (double *)malloc(sizeof(double) * to * abs(inc_x))) == NULL){
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  if (( y = (double *)malloc(sizeof(double) * to * abs(inc_y))) == NULL){
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }

  for(i = 0; i < to * to; i++) {
    a[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }
  for(i = 0; i < to * abs(inc_x); i++){
    x[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }
  for(i = 0; i < to * abs(inc_y); i++){
    y[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }

  for(m = from; m <= to; m += step) {
    n = m;

    clock_gettime(CLOCK_REALTIME, &start);
    for (l=0; l<loops; l++) {
      dgemv_(&trans, &m, &n, &alpha, a, &m, x, &inc_x, &beta, y, &inc_y);
    }
    clock_gettime(CLOCK_REALTIME, &stop);
    total_time += (double)(stop.tv_sec - start.tv_sec) + (double)((stop.tv_nsec - start.tv_nsec)) * 1.e-9;
    average_time = total_time / loops;

    fprintf(stderr, " %c %6d %6d : %10.2f MFlops %10.6f sec\n", trans, m, n, 2. * (double)m * (double)n / average_time * 1.e-6, total_time);
  }

  return 0;
}
