#include "cuter.h"
#include "CExample3/steepest_descent.h"

int MAINENTRY () {
  doublereal *x, *bl, *bu;
  char fname[10] = "OUTSDIF.d";
  integer nvar = 0, ncon = 0, nmax;
  integer funit = 42, ierr = 0, fout = 6;
  integer i;
  Status status;

  FORTRAN_OPEN(&funit, fname, &ierr);
  CDIMEN(&funit, &nvar, &ncon);

  if (ncon > 0) {
    printf("ERROR: Problem is not unconstrained\n");
    return 1;
  }

  x  = (doublereal *) malloc (sizeof(doublereal) * nvar);
  bl = (doublereal *) malloc (sizeof(doublereal) * nvar);
  bu = (doublereal *) malloc (sizeof(doublereal) * nvar);

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
