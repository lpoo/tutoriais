#include <stdio.h>
#include "steepest_descent.h"

/*
 * Each file testx.c is a different problem. The user will have to
 * implement his own file, defining objfun and gradfun.
 */

/*
 * This problem is
 *
 *  min f(x) = 3*x_1^2 + x_2^2
 *
 *  starting from point x0 = (2,10);
 *
 */

double objfun (double * x, unsigned int n) {
  (void)n;
  return 3*x[0]*x[0] + x[1]*x[1];
}

void gradfun (double * x, unsigned int n, double * g) {
  (void)n;

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
