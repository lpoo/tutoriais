#include "cuter.h"
#include "steepest_descent.h"

double objfun (double * x, unsigned int n) {
  double F = 0;
  int N = n;
  UFN(&N, x, &F);
  return F;
}

void gradfun (double * x, unsigned int n, double * g) {
  int N = n;
  UGR(&N, x, g);
}

int MAINENTRY () {
  double *x, *bl, *bu;
  char fname[10] = "OUTSDIF.d";
  int nvar = 0, ncon = 0, nmax;
  int funit = 42, ierr = 0, fout = 6;
  int i;
  Status status;

  FORTRAN_OPEN(&funit, fname, &ierr);
  CDIMEN(&funit, &nvar, &ncon);

  if (ncon > 0) {
    printf("ERROR: Problem is not unconstrained\n");
    return 1;
  }

  x  = (double *) malloc (sizeof(double) * nvar);
  bl = (double *) malloc (sizeof(double) * nvar);
  bu = (double *) malloc (sizeof(double) * nvar);

  USETUP(&funit, &fout, &nvar, x, bl, bu, &nmax);

  for (i = 0; i < nvar; i++) {
    if ( (bl[i] > -CUTE_INF) || (bu[i] < CUTE_INF) ) {
      printf("ERROR: Problem has bounds\n");
      return 1;
    }
  }

  SteepestDescent(x, nvar, &status);

  SD_Print(x, nvar, &status);

  free(x);
  free(bl);
  free(bu);

  return 0;
}
