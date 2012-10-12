#include "steepest_descent.h"

#define EPSILON 1e-6

/*
 * These functions are necessary for the software. They must be
 * implemented in a separate file by the user.
 */
void ufn (int * n, double * x, double * f);
void uofg (int * n, double * x, double * f, double * g, long int * grad);

double Norm (double * x, int n) {
  int i;
  double s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return sqrt(s);
}

double NormSqr (double * x, int n) {
  int i;
  double s = 0.0;

  for (i = 0; i < n; i++)
    s += x[i]*x[i];

  return s;
}

void SteepestDescent (double * x, int n, Status *status) { 
  double * g, f, fp;
  double * xp, lambda, ng_sqr;
  int i;
  long int one = 1;

  if ( (x == 0) || (status == 0) )
    return;

  g  = (double *) malloc(n * sizeof(double) );
  xp = (double *) malloc(n * sizeof(double) );
  status->iter = 0;
  status->n_objfun = 0;
  status->n_gradfun = 0;

  uofg(&n, x, &f, g, &one);
  status->n_objfun++;
  status->n_gradfun++;

  status->ng = Norm(g, n);

  while (status->ng > EPSILON) {
    lambda = 1;

    for (i = 0; i < n; i++) {
      xp[i] = x[i] - g[i];
    }

    ufn(&n, xp, &fp);
    status->n_objfun++;
    ng_sqr = status->ng*status->ng;

    while (fp > f - 0.5 * lambda * ng_sqr) {
      for (i = 0; i < n; i++) {
        xp[i] = x[i] - lambda*g[i];
      }
      lambda = lambda/2;
      ufn(&n, xp, &fp);
      status->n_objfun++;
    }

    for (i = 0; i < n; i++)
      x[i] = xp[i];

    uofg(&n, x, &f, g, &one);
    status->n_objfun++;
    status->n_gradfun++;
    status->ng = Norm(g, n);
    status->iter++;
  }

  status->f = f;

  free(xp);
  free(g);
}
                    
void SD_Print (double * x, int n, Status * status) {
  int i;

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
