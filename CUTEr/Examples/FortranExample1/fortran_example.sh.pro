#!/bin/bash
# Definitions for the GENERIC package
# N. Gould, D. Orban & Ph. Toint, November 7th, 2000

# Define a short acronym for the package
export PACK=fortran_example

# Subdirectory of ${CUTER}/common/src/pkg where the package lives
export PACKAGE=fortran_example

# Precision for which the package was written
# Valid values are "single", "double", "single double" and "double single"
export PACK_PRECISION="double"

# Define the name of the object files for the package which must lie in
# ${MYCUTER}/(precision)/bin
export PACKOBJS=""

export PACKLIBS="/home/abel/Tutoriais/tutoriais-lpoo/CUTEr/Examples/FortranExample1/gradient.o /home/abel/Tutoriais/tutoriais-lpoo/CUTEr/Examples/FortranExample1/gradientmain.o"

# Define the name of the package specification file if any. This possibly
# precision-dependent file must either lie in the current directory or in
# ${CUTER}/common/src/pkg/${PACKAGE}/ )
export SPECS=""
