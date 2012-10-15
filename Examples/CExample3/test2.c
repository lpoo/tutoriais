#include <stdio.h>
#include "steepest_descent.h"

/*
 * Each file testx.c is a different problem. The user will have to
 * implement his own file, defining objfun and gradfun.
 */

/*
 * This problem is
 *
 *  min f(x) = 2*x_1^2 + x_2^2
 *
 *  starting from point x0 = (2,2);
 *
 */

void ufn_ (int * n, double * x, double * f) {
  (void)n;
  *f = 3*x[0]*x[0] + x[1]*x[1];
}

void uofg_ (int * n, double * x, double * f, double * g, long int * grad) {
  (void)n;

  *f = 3*x[0]*x[0] + x[1]*x[1];
  if (*grad == 0)
    return;
  g[0] = 6*x[0];
  g[1] = 2*x[1];
}

int main () {
  double x[2];
  Status status;

  x[0] = 2;
  x[1] = 10;

  SteepestDescent(x, 2, &status);

  SD_Print(x, 2, &status);

  return 0;
}
