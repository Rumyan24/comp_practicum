import numpy as np

def Metod_Progonki(A, B):
    n = len(B)
    alpha = np.zeros(n - 1)
    beta = np.zeros(n)

    # Прямой ход
    alpha[0] = -A[0, 1] / A[0, 0]
    beta[0] = B[0] / A[0, 0]
    for i in range(1, n - 1):
        alpha[i] = -A[i, i + 1] / (A[i, i - 1] * alpha[i - 1] + A[i, i])
        beta[i] = (B[i] - A[i, i - 1] * beta[i - 1]) / (A[i, i - 1] * alpha[i - 1] + A[i, i])
    beta[n - 1] = (B[n - 1] - A[n - 1, n - 2] * beta[n - 2]) / (A[n - 1, n - 2] * alpha[n - 2] + A[n - 1, n - 1])

    # Обратный ход
    x = np.zeros(n)
    x[n - 1] = beta[n - 1]
    for i in range(n - 2, -1, -1):
        x[i] = alpha[i] * x[i + 1] + beta[i]

    return x

# Задаем матрицу системы
A = np.array([
    [16, -8, 0, 0, 0],
    [-7, 16, 5, 0, 0],
    [0, 12, 3, -4, 0],
    [0, 0, 12, -7, 1],
    [0, 0, 0, 7, 1]
])
B = np.array([0, -123, -68, 104, 20])

# Вызов функции и вывод на экран
print('Матрица A:')
print(A)
print('Вектор B:')
print(B)
solution = Metod_Progonki(A, B)
print('Решение системы:')
print(solution)
