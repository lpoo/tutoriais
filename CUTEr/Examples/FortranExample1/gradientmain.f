      program gradientmain
      
      implicit none
      
C     SCALAR ARGUMENTS
      integer n
      integer, parameter :: nmax = 100000
      double precision epsopt
      
C     ARRAY ARGUMENTS      
      double precision x(nmax)
      
      epsopt = 1.0d-6
      
      call inip(n,x)
      
      call gradient(n,x,epsopt)
      
      call endp(n,x)
      
      end
