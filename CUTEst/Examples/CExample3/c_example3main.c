#include "cutest.h"
#include "steepest_descent.h"

int MAINENTRY () {
  doublereal *x, *bl, *bu;
  char fname[10] = "OUTSDIF.d";
  integer nvar = 0, ncon = 0;
  integer funit = 42, ierr = 0, fout = 6, io_buffer = 11;
  integer i;
  Status status;
  integer st;

  FORTRAN_open(&funit, fname, &ierr);
  CUTEST_cdimen(&st, &funit, &nvar, &ncon);

  if (ncon > 0) {
    printf("ERROR: Problem is not unconstrained\n");
    return 1;
  }

  x  = (doublereal *) malloc (sizeof(doublereal) * nvar);
  bl = (doublereal *) malloc (sizeof(doublereal) * nvar);
  bu = (doublereal *) malloc (sizeof(doublereal) * nvar);

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
