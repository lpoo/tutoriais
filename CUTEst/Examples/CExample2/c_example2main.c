#include "cutest.h"
#include "steepest_descent.h"

void ufn (int * st, int * n, double * x, double * f) {
  CUTEST_ufn(st, n, x, f);
}

void uofg (int * st, int * n, double * x, double * f, double * g, bool * grad) {
  CUTEST_uofg(st, n, x, f, g, grad);
}

int MAINENTRY () {
  double *x, *bl, *bu;
  char fname[10] = "OUTSDIF.d";
  int nvar = 0, ncon = 0;
  int funit = 42, ierr = 0, fout = 6, io_buffer = 11;
  int i;
  Status status;
  int st = 0;

  FORTRAN_open(&funit, fname, &ierr);
  CUTEST_cdimen(&st, &funit, &nvar, &ncon);

  if (ncon > 0) {
    printf("ERROR: Problem is not unconstrained\n");
    return 1;
  }

  x  = (double *) malloc (sizeof(double) * nvar);
  bl = (double *) malloc (sizeof(double) * nvar);
  bu = (double *) malloc (sizeof(double) * nvar);

  CUTEST_usetup(&st, &funit, &fout, &io_buffer, &nvar, x, bl, bu);

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

  FORTRAN_close(&funit, &ierr);

  return 0;
}
