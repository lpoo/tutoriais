#include <stdio.h>
#include "steepest_descent.h"

/*
 * Each file testx.c is a different problem. The user will have to
 * implement his own file, defining objfun and gradfun.
 */

/*
 * This problem is
 *
 *  min f(x) = x_1^4 + x_2^4
 *
 *  starting from point x0 = (2,1);
 *
 */

double objfun (double * x, unsigned int n) {
  double xx1 = x[0]*x[0], xx2 = x[1]*x[1];
  (void)n;
  return xx1*xx1 + xx2*xx2;
}

void gradfun (double * x, unsigned int n, double * g) {
  (void)n;

  g[0] = 4*x[0]*x[0]*x[0];
  g[1] = 4*x[1]*x[1]*x[1];
}

int main () {
  double x[2];
  Status status;

  x[0] = 2;
  x[1] = 1;

  SteepestDescent(x, 2, &status);

  SD_Print(x, 2, &status);

  return 0;
}
