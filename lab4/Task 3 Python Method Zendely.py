import numpy as np

def seidel(A, b, x0, epsilon, max_iterations):
    n = len(A)
    x = x0.copy()

    for i in range(max_iterations):
        x_new = np.zeros(n)
        for j in range(n):
            s1 = np.dot(A[j, :j], x_new[:j])
            s2 = np.dot(A[j, j + 1:], x[j + 1:])
            x_new[j] = (b[j] - s1 - s2) / A[j, j]
        if np.allclose(x, x_new, atol=epsilon):
            return x_new
        x = x_new
    return x

# Заполнение матрицы и правой части
A = np.array([
    [-14, 6, 1, -5],
    [-6, 27, 7, -6],
    [7, -5, -23, -8],
    [3, -8, -7, 26]
])
b = np.array([95, -41, 69, 27])
x0 = np.zeros(4)
eps = 0.01 # Точность
max_iter = 100 # Число итераций

x = seidel(A, b, x0, eps, max_iter)
print('Решение системы методом Зейделя:', x)
