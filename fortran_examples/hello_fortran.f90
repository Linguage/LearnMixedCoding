program hello_world
  implicit none
  integer :: i
  
  print *, "hello,world"

  do i = 1, 10, 1
    print *,i
  end do
  
end program hello_world