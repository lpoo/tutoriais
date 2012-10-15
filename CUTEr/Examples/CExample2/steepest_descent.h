#ifndef steepest_descent_h
#define steepest_descent_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Status {
  int iter;
  double f, ng;
  int n_objfun, n_gradfun;
} Status;

double Norm (double * x, int n);
double NormSqr (double * x, int n);
void SteepestDescent (double * x, int n, Status * status);
void SD_Print (double * x, int n, Status * status);


#endif
