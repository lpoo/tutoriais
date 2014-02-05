all: c fortran

c:
	for dir in C*; do (cd $$dir; make all run cutest); done

fortran:
	for dir in Fortran*; do (cd $$dir; make all run cutest); done

clean:
	for dir in C* Fortran*;  do (cd $$dir; make clean); done

