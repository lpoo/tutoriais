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
 *  starting from pomy_integer x0 = (2,2);
 *
 */

void ufn_ (my_integer * n, my_doublereal * x, my_doublereal * f) {
  (void)n;
  *f = 3*x[0]*x[0] + x[1]*x[1];
}

void uofg_ (my_integer * n, my_doublereal * x, my_doublereal * f, my_doublereal * g, my_logical * grad) {
  (void)n;

  *f = 3*x[0]*x[0] + x[1]*x[1];
  if (*grad == 0)
    return;
  g[0] = 6*x[0];
  g[1] = 2*x[1];
}

my_integer main () {
  my_doublereal x[2];
  Status status;

  x[0] = 2;
  x[1] = 10;

  SteepestDescent(x, 2, &status);

  SD_Print(x, 2, &status);

  return 0;
}
