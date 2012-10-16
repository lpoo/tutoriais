default: error

c:
	for dir in $$(ls | grep C); do (cd $$dir; make all run cuter); done

fortran:
	for dir in $$(ls | grep Fortran); do (cd $$dir; make all run cuter); done

error:
	echo "Valid options:"
	echo "  make c"
