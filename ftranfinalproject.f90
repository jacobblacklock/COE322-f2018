program goldbach

implicit none
integer :: x,i
logical :: isprime


call psequence(10000)

contains
logical function primetest(x)
integer :: x,y
logical :: prime

prime = .true.

if (x==0 .or. x==1) then
                prime = .false.
else 
do y = 2,x
        if (x /= y) then
                if (MOD(x,y) == 0) then
                         prime = .false.
                end if
        end if
        if (prime == .false.) then
                exit
        end if
end do

end if

primetest = prime
end function

subroutine psequence(i)
integer :: i,j,k,q,r,p
integer, dimension(i) :: A
k = 0
j = 0
do while (k<i)
                if (primetest(j)) then
                        p = j
                        q = qsequence(j+1)
                        r = 2*p - q
                        if (primetest(r)) then
                                A(k+1) = ABS(p - q)
                        else
                                do while (.NOT. primetest(r))
                                        q = qsequence(q+1)
                                        r = 2*p -q
                                end do
                                A(k+1) = ABS(p - q) 
                        end if
                        k = k + 1
                        j = j + 1
                end if
                j = j + 1
end do
call mean(A,i,1)
call mean(A,i,2500)
call mean(A,i,5000)
call mean(A,i,7500)
print *, "The average distance between p and q increases as p gets
larger"
print *,"Median = ", (A(i/2))
!A is an array of the distance between p and q for the first 10000 prime
!numbers
!of the p sequence


end subroutine psequence

integer function qsequence(l)
integer :: l
do
        if (primetest(l)) then
                qsequence = l
                exit
        end if
        l = l + 1
end do

end function qsequence

subroutine mean(A,i,k)
integer, dimension(i) :: A
integer :: n,val,i,k
real :: average
val = 0
do n = k,i
        val = val + A(n)
end do
average = val/(i-k)
print *,"Average distance from prime number",k,"=", average
end subroutine mean




end program
