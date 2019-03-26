!hw6


program hw6

implicit none
integer :: x
logical :: isprime

print *, "input number:"
read *,x

isprime = primetest(x)

if (isprime==.false.) then
print *, "not prime"
else
print *, "prime"
end if


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

subroutine howmanynumbers
integer :: i
print *,"how many primes do you want?"
read *,i
end subroutine howmanynumbers

end program
