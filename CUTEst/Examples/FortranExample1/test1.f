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

C     Number of variables 

      n = 2

C     Initial point

      x(1) = 1.0d0
      x(2) = 2.0d0
      
      end
      
C     ******************************************************************
C     ******************************************************************

      subroutine evalf(n,x,f)

      implicit none

C     SCALAR ARGUMENTS
      integer n
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
          
      f = 0.5d0 * x(1) ** 2 + 0.5d0 * x(2) ** 2 
      end

C     ******************************************************************
C     ******************************************************************

      subroutine evalg(n,x,g)

      implicit none

C     SCALAR ARGUMENTS
      integer n

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
      
      g(1) = x(1)
      g(2) = x(2)

      end 

C     ******************************************************************
C     ******************************************************************

      subroutine endp(n,x,f,g,exitflag)

      implicit none

C     SCALAR ARGUMENTS
      integer n, exitflag

C     ARRAY ARGUMENTS
      double precision x(n), f, g(n)

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
