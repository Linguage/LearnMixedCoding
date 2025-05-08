subroutine add_integers_fortran(a, b, result)
    implicit none
    integer, intent(in) :: a, b
    integer, intent(out) :: result
    result = a + b
    print *, "Hello from Fortran! Calculated sum."
end subroutine add_integers_fortran