#ifndef steepest_descent_h
#define steepest_descent_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int my_integer;
typedef bool my_logical;
typedef double my_doublereal;

typedef struct _Status {
  my_integer iter;
  my_doublereal f, ng;
  my_integer n_objfun, n_gradfun;
  my_integer exitflag;
} Status;

typedef struct _Param {
  my_integer maxiter;
  my_doublereal alpha;
} Param;

void DefaultParam (Param *param);
void ReadParam (Param *param);
my_doublereal Norm (my_doublereal * x, my_integer n);
my_doublereal NormSqr (my_doublereal * x, my_integer n);
void SteepestDescent (my_doublereal * x, my_integer n, Status * status, Param * param);
void SD_Print (my_doublereal * x, my_integer n, Status * status);


#endif
