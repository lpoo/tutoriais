#include "steepest_descent.h"

#define EPSILON 1e-6

/*
 * These functions are necessary for the software. They must be
 * implemented in a separate file by the user.
 */
void cutest_ufn_ (my_integer *, my_integer * n, my_doublereal * x, my_doublereal * f);
void cutest_uofg_ (my_integer *, my_integer * n, my_doublereal * x, my_doublereal * f,
    my_doublereal * g, my_logical * grad);

my_doublereal NormInf (my_doublereal * x, my_integer n) {
  my_integer i;
  my_doublereal s = 0.0;

  for (i = 0; i < n; i++) {
    my_doublereal absxi = fabs(x[i]);
    if (absxi > s) 
      s = absxi;
  }

  return s;
}

my_doublereal Norm (my_doublereal * x, my_integer n) {
  my_integer i;
  my_doublereal s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return sqrt(s);
}

my_doublereal NormSqr (my_doublereal * x, my_integer n) {
  my_integer i;
  my_doublereal s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return s;
}

void SteepestDescent (my_doublereal * x, my_integer n, Status *status) { 
  my_doublereal * g, f, fp;
  my_doublereal * xp, lambda, ng_sqr;
  my_doublereal alpha = 1e-4;
  my_integer i, maxiter = 1e4;
  my_integer st;
  my_logical one = 1;

  if ( (x == 0) || (status == 0) )
    return;

  g  = (my_doublereal *) malloc(n * sizeof(my_doublereal) );
  xp = (my_doublereal *) malloc(n * sizeof(my_doublereal) );
  status->iter = 0;
  status->n_objfun = 0;
  status->n_gradfun = 0;
  status->exitflag = 0;

  cutest_uofg_(&st, &n, x, &f, g, &one);
  status->n_objfun++;
  status->n_gradfun++;

  status->ng = NormInf(g, n);

  while (status->ng > EPSILON) {
    lambda = 1;

    for (i = 0; i < n; i++) {
      xp[i] = x[i] - g[i];
    }

    cutest_ufn_(&st, &n, xp, &fp);
    status->n_objfun++;
    ng_sqr = status->ng*status->ng;

    while (fp > f - alpha * lambda * ng_sqr) {
      for (i = 0; i < n; i++) {
        xp[i] = x[i] - lambda*g[i];
      }
      lambda = lambda/2;
      cutest_ufn_(&st, &n, xp, &fp);
      status->n_objfun++;
    }

    for (i = 0; i < n; i++)
      x[i] = xp[i];

    cutest_uofg_(&st, &n, x, &f, g, &one);
    status->n_objfun++;
    status->n_gradfun++;
    status->ng = NormInf(g, n);
    status->iter++;
    if (status->iter >= maxiter) {
      status->exitflag = 1;
      break;
    }
  }

  status->f = f;

  free(xp);
  free(g);
}
                    
void SD_Print (my_doublereal * x, my_integer n, Status * status) {
  my_integer i;

  if ( (x == 0) || (status == 0) )
    return;

  if (status->exitflag == 0) {
    printf("Converged to solution\n");
  } else if (status->exitflag == 1) {
    printf("Maximum iterations reached\n");
  }
  printf("x = (%lf", x[0]);
  for (i = 1; i < n; i++)
    printf(",%lf", x[i]);
  printf(")\n");

  printf("Iter          = %d\n", status->iter);
  printf("f(x)          = %lf\n", status->f);
  printf("|g(x)|        = %lf\n", status->ng);
  printf("objfun calls  = %d\n", status->n_objfun);
  printf("gradfun calls = %d\n", status->n_gradfun);
  printf("exitflag      = %d\n", status->exitflag);
  printf("\n");
}
