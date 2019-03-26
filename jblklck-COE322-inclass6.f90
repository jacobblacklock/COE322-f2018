!module in class challenge


module PointMod

type Point
        real :: x,y
end type Point

type LinearFunction
        type(Point) :: m,n
end type LinearFunction

contains
real function distance(p,q)
        type(Point) :: p,q
        real :: x1,y1,x2,y2
        x1 = p%x
        y1 = p%y
        x2 = q%x
        y2 = q%y
        distance = SQRT((x2-x1)**2 + (y2-y1)**2)
end function

real function evaluate_at(line,x)
        type(LinearFunction) :: line
        type(Point) :: m,n
        real :: x,y,a,b,c,d
        m = line%m
        n = line%n
        a = m%x
        b = m%y
        c = n%x
        d = n%y
        slope = (d - b)/(c - a)
        yint = b - (slope * a)
        fofx = (slope * x) + yint
        evaluate_at = fofx
end function
end module PointMod

program main
use PointMod
type(Point) :: p,q
type(LinearFunction) :: line
real :: x,y

p%x = 1
p%y = 1
q%x = 3
q%y = 3


print *,"Distance = ",distance(p,q)

line%m = p
line%n = q

x = 4
y = evaluate_at(line,x)

print *, "(",x,",",y,")"

end program main
