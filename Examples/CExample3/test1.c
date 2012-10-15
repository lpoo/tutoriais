#include <stdio.h>
#include "steepest_descent.h"

/*
 * Each file testx.c is a different problem. The user will have to
 * implement his own file, defining objfun and gradfun.
 */

/*
 * This problem is
 *
 *  min f(x) = 0.5*(x_1^2 + x_2^2)
 *
 *  starting from point x0 = (1,2);
 *
 */

void ufn_ (int * n, double * x, double * f) {
  (void)n;
  *f =  0.5 * (x[0]*x[0] + x[1]*x[1]);
}

void uofg_ (int * n, double * x, double * f, double * g, long int * grad) {
  unsigned int i;

  *f = 0.5 * (x[0]*x[0] + x[1]*x[1]);
  if (*grad == 0)
    return;
  for (i = 0; i < *n; i++)
    g[i] = x[i];
}

int main () {
  double x[2];
  Status status;

  x[0] = 1;
  x[1] = 2;

  SteepestDescent(x, 2, &status);

  SD_Print(x, 2, &status);

  return 0;
}
