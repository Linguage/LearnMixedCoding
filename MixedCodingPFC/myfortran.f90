subroutine pde_solver(u, n)
    ! 用显式欧拉法积分一维热传导方程 du/dt = alpha*d2u/dx2
    implicit none
    integer, intent(in) :: n
    real(8), intent(out) :: u(n)
    real(8) :: alpha, dx, dt, t, u_new(n)
    integer :: i, steps, j

    alpha = 0.01
    dx = 1.0d0/(n-1)
    dt = 0.4d0*dx*dx/alpha
    steps = 100

    ! 初始条件
    do i=1,n
        u(i) = 0.0d0
    end do
    u(n/2) = 1.0d0

    do j=1,steps
        u_new = u
        do i=2,n-1
            u_new(i) = u(i) + alpha*dt/(dx*dx)*(u(i+1)-2*u(i)+u(i-1))
        end do
        u = u_new
    end do
end subroutine pde_solver
