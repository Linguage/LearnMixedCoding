import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('data.txt')
x = data[:,0]
u = data[:,1]

plt.plot(x, u, label='PDE Solution')
plt.xlabel('x')
plt.ylabel('u')
plt.title('1D Heat Equation Solution (Fortran->C++->Python)')
plt.legend()
plt.grid()
plt.show()
