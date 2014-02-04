      subroutine inip(n,x)

      implicit none

C     SCALAR ARGUMENTS
      integer n

C     ARRAY ARGUMENTS
      double precision x(*)
      
C     This subroutine must set some problem data. 
C
C     Parameters of the subroutine:
C
C     On Entry:
C
C     This subroutine has no input parameters.
C
C     On Return
C
C     n        integer,
C              number of variables,
C
C     x        double precision x(n),
C              initial point.

C     LOCAL SCALARS
      integer i

C     CUTER STUFF - Include by Abel
      integer err, ifile, nt, m
      double precision bl(n), bu(n)
      integer st

      ifile = 30
      OPEN(ifile, FILE='OUTSDIF.d', FORM='FORMATTED',
     $     STATUS='OLD',IOSTAT=err)
      REWIND ifile
      IF (err.NE.0) THEN
        WRITE(*,*)'Could not open the OUTSDIF.d file'
        STOP
      ENDIF

      CALL cutest_cdimen(st, ifile, nt, m)

      if (m.GT.0) THEN
        WRITE(*,*)'Cannot handle constraints' 
        STOP
      ENDIF

      CALL cutest_usetup(st, ifile, 7, 11, n, x, bl, bu)

      DO i = 1,n
        IF ((bl(i).GT.-1.0D20).OR.(bu(i).LT.1.0D20)) THEN
          WRITE(*,*)'Cannot handle boxes'
          STOP
        ENDIF
      ENDDO
      
C     Removed some lines.
C     End of CUTER STUFF
      
      end
      
C     ******************************************************************
C     ******************************************************************

      subroutine evalf(n,x,f)

      implicit none

C     SCALAR ARGUMENTS
      integer n, st
      double precision f

C     ARRAY ARGUMENTS
      double precision x(n)

C     This subroutine must compute the objective function. 
C
C     Parameters of the subroutine:
C
C     On Entry:
C
C     n        integer,
C              number of variables,
C
C     x        double precision x(n),
C              current point,
C
C     On Return
C
C     f        double precision,
C              objective function value at x,

C     Objective function
      CALL cutest_ufn(st, n, x, f)
          
      end

C     ******************************************************************
C     ******************************************************************

      subroutine evalg(n,x,g)

      implicit none

C     SCALAR ARGUMENTS
      integer n, st

C     ARRAY ARGUMENTS
      double precision g(n),x(n)

C     This subroutine must compute the gradient vector of the objective
C     function. 
C
C     Parameters of the subroutine:
C
C     On Entry:
C
C     n        integer,
C              number of variables,
C
C     x        double precision x(n),
C              current point,
C
C     On Return
C
C     g        double precision g(n),
C              gradient vector of the objective function evaluated at x,

C     Gradient vector
      
      CALL cutest_ugr(st, n, x, g)

      end 

C     ******************************************************************
C     ******************************************************************

      subroutine endp(n,x)

      implicit none

C     SCALAR ARGUMENTS
      integer n

C     ARRAY ARGUMENTS
      double precision x(n)

C     This subroutine can be used to do some extra job after the solver
C     has found the solution.
C
C     Parameters of the subroutine:
C
C     The paraemters of this subroutine are the same parameters of
C     subroutine inip. But in this subroutine there are not output
C     parameter. All the parameters are input parameters.

C     LOCAL SCALAR
      integer i
      
      write(*,*)'Solution:'
      do i = 1,n
          write(*,*)x(i)
      end do
      
      end 
