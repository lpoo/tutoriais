#ifndef steepest_descent_h
#define steepest_descent_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Status {
  unsigned int iter;
  double f, ng;
  unsigned int n_objfun, n_gradfun;
} Status;

double Norm (double * x, unsigned int n);
double NormSqr (double * x, unsigned int n);
void SteepestDescent (double * x, unsigned int n, Status * status);
void SD_Print (double * x, unsigned int n, Status * status);


#endif
