#include "cutest.h"
#include "steepest_descent.h"
#include "string.h"

void WriteTableLine (integer nvar, Status *status) {
  char pname[10];
  char filename[25];
  char vname[10*nvar];
  doublereal calls[4], time[2];
  integer st = 0;
  FILE *f;
  int i = 0;

  CUTEST_unames(&st, &nvar, pname, vname);
  while (pname[i] != ' ') ++i;
  pname[i] = 0;
  strcpy(filename, pname);
  strcat(filename, ".tableline");

  f = fopen(filename, "w");

  fprintf(f, "|Problem |EXITFLAG |   TIME     |     FVAL    |  GRADNORM   |\n");
  fprintf(f, "%-9s ", pname);
  if (status->exitflag == 0)
    fprintf(f, "Converged ");
  else
    fprintf(f, "fail      ");

  CUTEST_ureport(&st, calls, time);

  fprintf(f, "%8.6e ", time[0]+time[1]);
  fprintf(f, "%+8.6e ", status->f);
  fprintf(f, "%+8.6e\n", status->ng);

  fclose(f);
}

int MAINENTRY () {
  doublereal *x, *bl, *bu;
  char fname[10] = "OUTSDIF.d";
  integer nvar = 0, ncon = 0;
  integer funit = 42, ierr = 0, fout = 6, io_buffer = 11;
  integer i;
  Status status;
  integer st;
  Param param;
  DefaultParam(&param);
  ReadParam(&param);

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

  SteepestDescent(x, nvar, &status, &param);

  SD_Print(x, nvar, &status);

  WriteTableLine(nvar, &status);

  free(x);
  free(bl);
  free(bu);

  FORTRAN_close(&funit, &ierr);

  return 0;
}
