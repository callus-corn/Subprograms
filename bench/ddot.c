#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "blas.h"

int main(int argc, char *argv[]){

  double *x, *y;
  double result;
  int m;
  int inc_x = 1;
  int inc_y = 1;

  int from =   1;
  int to   = 200;
  int step =   1;
  int loops = 1;

  struct timespec start = { 0, 0 }, stop = { 0, 0 };
  double total_time, average_time;

  int i, l;

  argc--;argv++;

  if (argc > 0) { from     = atol(*argv);	argc--; argv++;}
  if (argc > 0) { to       = atol(*argv);	argc--; argv++;}
  if (argc > 0) { step     = atol(*argv);	argc--; argv++;}
  if (argc > 0) { loops    = atol(*argv);	argc--; argv++;}

  if (( x = (double *)malloc(sizeof(double) * to * abs(inc_x))) == NULL){
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  if (( y = (double *)malloc(sizeof(double) * to * abs(inc_y) )) == NULL){
    fprintf(stderr,"Out of Memory!!\n");exit(1);
  }
  for(i = 0; i < to * abs(inc_x); i++){
    x[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }
  for(i = 0; i < to * abs(inc_y); i++){
    y[i] = ((double) rand() / (double) RAND_MAX) - 0.5;
  }

  fprintf(stderr, "From : %3d  To : %3d Step = %3d Inc_x = %d Inc_y = %d Loops = %d\n", from, to, step,inc_x,inc_y,loops);
  fprintf(stderr, "   SIZE       Flops\n");

  for(m = from; m <= to; m += step) {
    total_time = 0;
    for (l = 0; l < loops; l++) {
      clock_gettime(CLOCK_REALTIME, &start);

      result = ddot_(&m, x, &inc_x, y, &inc_y);

      clock_gettime(CLOCK_REALTIME, &stop);
      total_time += (double)(stop.tv_sec - start.tv_sec) + (double)((stop.tv_nsec - start.tv_nsec)) * 1.e-9;
    }
    average_time = total_time / loops;

    fprintf(stderr, " %6d : %10.2f MFlops %10.6f sec \n", m, 2. * (double)m / average_time * 1.e-6, total_time);
  }

  return 0;
}
