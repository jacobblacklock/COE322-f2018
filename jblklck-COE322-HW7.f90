!hw6


program hw6

implicit none
integer :: x,i
logical :: isprime

print *,"how many primes do you want?"
read *,i

call howmanynumbers(i)

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

subroutine howmanynumbers(i)
integer :: i,j,k
k = 0
j = 0
do while (k<i)
        do
                if (primetest(j)) then
                        print *,j
                        k = k + 1
                        j = j + 1
                        exit
                end if
                j = j + 1
        end do
end do


end subroutine howmanynumbers

end program
