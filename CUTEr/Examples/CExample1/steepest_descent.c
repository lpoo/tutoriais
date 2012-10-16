#include "steepest_descent.h"

#define EPSILON 1e-6

typedef unsigned int uint;

/*
 * These functions are necessary for the software. They must be
 * implemented in a separate file by the user.
 */
double objfun  (double * x, uint n);
void   gradfun (double * x, uint n, double * g);

double Norm (double * x, uint n) {
  uint i;
  double s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return sqrt(s);
}

double NormSqr (double * x, uint n) {
  uint i;
  double s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return s;
}

void SteepestDescent (double * x, uint n, Status *status) { 
  double * g, f, fp;
  double * xp, lambda, ng_sqr;
  double alpha = 1e-4;
  uint maxiter = 1e4;
  uint i;

  if ( (x == 0) || (status == 0) )
    return;

  g  = (double *) malloc(n * sizeof(double) );
  xp = (double *) malloc(n * sizeof(double) );
  status->iter = 0;
  status->n_objfun = 0;
  status->n_gradfun = 0;

  f = objfun(x, n);
  status->n_objfun++;
  gradfun(x, n, g);
  status->n_gradfun++;

  status->ng = Norm(g, n);

  while (status->ng > EPSILON) {
    lambda = 1;

    for (i = 0; i < n; i++) {
      xp[i] = x[i] - g[i];
    }

    fp = objfun(xp, n);
    status->n_objfun++;
    ng_sqr = status->ng*status->ng;

    while (fp > f - alpha * lambda * ng_sqr) {
      for (i = 0; i < n; i++) {
        xp[i] = x[i] - lambda*g[i];
      }
      lambda = lambda/2;
      fp = objfun(xp, n);
      status->n_objfun++;
    }

    for (i = 0; i < n; i++)
      x[i] = xp[i];

    f = objfun(x, n);
    status->n_objfun++;
    gradfun(x, n, g);
    status->n_gradfun++;
    status->ng = Norm(g, n);
    status->iter++;
    if (status->iter >= maxiter)
      break;
  }

  status->f = f;

  free(xp);
  free(g);
}
                    
void SD_Print (double * x, uint n, Status * status) {
  uint i;

  if ( (x == 0) || (status == 0) )
    return;

  printf("x = (%lf", x[0]);
  for (i = 1; i < n; i++)
    printf(",%lf", x[i]);
  printf(")\n");

  printf("Iter          = %d\n", status->iter);
  printf("f(x)          = %lf\n", status->f);
  printf("|g(x)|        = %lf\n", status->ng);
  printf("objfun calls  = %d\n", status->n_objfun);
  printf("gradfun calls = %d\n", status->n_gradfun);
  printf("\n");
}
