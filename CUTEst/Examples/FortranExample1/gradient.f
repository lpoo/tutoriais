      subroutine gradient(n,x,epsopt)
      
      implicit none
      
C     SCALAR ARGUMENTS
      integer n,flag

C     ARRAY ARGUMENTS
      double precision x(n),epsopt
      
C     This subroutine implements the gradient method with line search
C     by Armijo's rule. 
C
C     Author: Leandro Prudente
C     e-mail: lfprudente@gmail.com
C     Date:   15/10/2012 
C
C     Parameters of the subroutine:
C
C     On Entry:
C
C     n        integer,
C              number of variables,
C
C     x        double precision x(n),
C              initial point.
C
C     epsopt   integer,
C              optimal tolerance.
C
C     On Return:
C
C     x        double precision x(n),
C              solution point.

 
C     LOCAL SCALARS
      integer it,i
      double precision f,gsupn
      real time

C     ARRAY ARGUMENTS
      double precision g(n),d(n)
      
      time = secnds(0.0)
      
C     ==================================================================
C     Print initial information
C     ==================================================================

      write(*,1000)
      write(*,1010) n

C     ==================================================================
C     Initialization
C     ==================================================================      
      
      it = 0
      
C     Compute objective function

      call evalf(n,x,f)

C     Compute objective function gradient and its norm

      call evalg(n,x,g)
      
      gsupn = 0.0d0
      do i = 1,n
          gsupn = max( gsupn, abs(g(i)) )
      end do
      
C     ==================================================================
C     Main loop
C     ==================================================================

 100  continue

C     ==================================================================
C     Print information of this iteration
C     ==================================================================

C     if ( mod(it,10) .eq. 0 ) then
C         write(*,1020)
C     end if
      
C     write(*,1030) it,f,gsupn
      
C     ==================================================================
C     Test stopping criteria
C     ==================================================================

C     Test optimality 
      
      if ( gsupn .le. epsopt ) then       
          
          time = secnds(time)
          write (*,1040)
          write(*,1060) time
          write(*,1020)
          write(*,1030) it, f, gsupn
          
          return
      end if
      
C     Test whether the number of iterations is exhausted

      if ( it .ge. 10000 ) then
      
          time = secnds(time)
          write(*,1050)
          write(*,1060) time
          
          return
          
      end if    
    
C     ==================================================================
C     Iteration
C     ==================================================================

      it = it + 1
      
      do i = 1,n
          d(i) = - g(i)
      end do    
      
      call armijo(n,x,d)

C     ==================================================================
C     Prepare for the next iteration
C     ==================================================================              
      
C     Compute objective function

      call evalf(n,x,f)

C     Compute objective function gradient and its norm

      call evalg(n,x,g)
      
      gsupn = 0.0d0
      do i = 1,n
          gsupn = max( gsupn, abs(g(i)) )
      end do 
      
C     ==================================================================
C     Iterate
C     ==================================================================

      go to 100

C     ==================================================================
C     End of main loop
C     ==================================================================

C     NON-EXECUTABLE STATEMENTS

 1000 format(/,1X,'===============',
     +       /,1X,'Gradient method', 
     +       /,1X,'===============')
     
 1010 format(/,1X,'Number of variables  : ',I7)   
     
 1020 format(/,'it ',5X,'objective',3X,'norm',/,8X,'function',4X,'grad') 
 
 1030 format(I5,1X,1P,D10.2,1P,D10.2)
 
 1040 format(/,1X,'Solution was found!')
 
 1050 format(/,1X,'Maximum of iterations reached!',
     +      /,1X,'The optimality tolerances could not be achieved.')
 1060 format(/,1X,'Total CPU time in seconds: ',F8.2,/)    
      
      end
      
C     ==================================================================
C     ==================================================================      
      
      subroutine armijo(n,x,d)
      
      implicit none
      
C     SCALAR ARGUMENTS
      integer n

C     ARRAY ARGUMENTS
      double precision x(n),d(n)
      
C     This subroutine computes a line search in direction d using Armijo's
C     rule.

C     On Entry:
C
C     n        integer,
C              number of variables,
C
C     x        double precision x(n),
C              initial point,
C
C     d        double precision d(n)
C              search direction.   
C
C     On Return
C
C     x        double precision x(n),
C              a point that satisfies the Armijo's rule.

C     LOCAL SCALARS
      integer it,i
      double precision alpha,gtd,t,f,ftrial
      
C     LOCAL ARRAYS
      double precision g(n),xtrial(n)      
      
      it = 0
      alpha = 1.0d-4
      
      call evalg(n,x,g)
 
      gtd = 0.0d0
      do i = 1,n
          gtd = gtd + g(i) * d(i)
      end do
      
      call evalf(n,x,f)  
      
C     ==================================================================
C     Backtraking
C     ==================================================================   

 100  continue     
      
      t = 2.0d0 ** ( -it )
      
      do i = 1,n
          xtrial(i) = x(i) + t * d(i)
      end do   
        
      call evalf(n,xtrial,ftrial)     
      
      if ( ftrial .le. ( f + alpha * t * gtd )  ) then
          x = xtrial
          
          return
          
      end if
      
      if ( it .ge. 1.0d4 ) then
      
          x = xtrial
          
          write(*,*)'Armijo`s rule failed!'
          
          return
          
       end if
      
      it = it + 1
      
      go to 100
      
      end 
