! fortran homework 4

program hw4
implicit none

integer :: x,y,prime,zero,one,two
zero = 0
one = 1
two = 2
print *,zero,"is not prime: it is divisible by", two
print *,one,"is not prime: it is divisible by",one

do x = 2,99
        prime = 1
        do y = 2,x
                if (x /= y) then
                        if (MOD(x,y) == 0) then
                         print *,x,"is not prime: it is divisible by",y
                         prime = 0
                        end if
                end if
                if (prime == 0) then
                        exit
                end if
        end do
        if (prime == 1) then
                print *,x,"is prime"
        end if
end do

end program
