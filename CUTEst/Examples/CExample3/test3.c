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
 *  starting from pomy_integer x0 = (2,1);
 *
 */

void cutest_ufn_ (my_integer * st, my_integer * n, my_doublereal * x, my_doublereal * f) {
  (void)st;
  my_doublereal xx1 = x[0]*x[0], xx2 = x[1]*x[1];
  (void)n;
  *f = xx1*xx1 + xx2*xx2;
}

void cutest_uofg_ (my_integer * st, my_integer * n, my_doublereal * x, my_doublereal *
    f, my_doublereal * g, my_logical * grad) {
  (void)st;
  my_doublereal xx1 = x[0]*x[0], xx2 = x[1]*x[1];
  (void)n;
  *f = xx1*xx1 + xx2*xx2;

  if (*grad == 0)
    return;
  g[0] = 4*x[0]*x[0]*x[0];
  g[1] = 4*x[1]*x[1]*x[1];
}

my_integer main () {
  my_doublereal x[2];
  Status status;
  Param param;
  DefaultParam(&param);
  ReadParam(&param);

  x[0] = 2;
  x[1] = 1;

  SteepestDescent(x, 2, &status, &param);

  SD_Print(x, 2, &status);

  return 0;
}
