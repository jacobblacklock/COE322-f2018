program loopsandstuff

implicit none

integer :: u,v,w


do
     do u = 1,99
        v = 1
        w = 1
        do while (w<100)
                if (u**2 + v**2 == w**2) then
                        print *,"u=",u,"v=",v,"w=",w
                end if
        exit
        end do
        do v = 2,99
                do while (w<100)
                        if (u**2 + v**2 == w**2) then
                                print *,"u=",u,"v=",v,"w=",w
                        end if
                exit
                end do
                do w = 2,99
                        do while (w<100)
                                if (u**2 + v**2 == w**2) then
                                        print *,"u=",u,"v=",v,"w=",w
                                end if
                        exit
                        end do
                end do
        end do
     end do
exit
end do

end program
