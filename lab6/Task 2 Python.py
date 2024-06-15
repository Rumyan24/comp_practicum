import numpy as np
import matplotlib.pyplot as plt


# Определяем функцию для оптимизации
def f(x1, x2):
    return 7 * x1 ** 2 + 2 * x1 * x2 + 5 * x2 ** 2 + x1 - 10 * x2


# Определяем градиенты функции
def gradient(x1, x2):
    df_dx1 = 14 * x1 + 2 * x2 + 1
    df_dx2 = 2 * x1 + 10 * x2 - 10
    return np.array([df_dx1, df_dx2])


# Начальная точка
x = np.array([0.0, 0.0])

# Параметры алгоритма
alpha = 0.01
epsilon = 1e-6
max_iter = 1000

# Списки для хранения траектории
trajectory = [x.copy()]

# Алгоритм наискорейшего спуска
for _ in range(max_iter):
    grad = gradient(x[0], x[1])
    x = x - alpha * grad
    trajectory.append(x.copy())

    # Проверка условия остановки
    if np.linalg.norm(grad) < epsilon:
        break

# Вывод результатов
print('Оптимальные значения:')
print('x1:', x[0])
print('x2:', x[1])
print('Минимальное значение функции:', f(x[0], x[1]))

# Визуализация траектории
trajectory = np.array(trajectory)
plt.plot(trajectory[:, 0], trajectory[:, 1], 'r.-')
plt.xlabel('x1')
plt.ylabel('x2')
plt.title('Steepest Descent Trajectory')
plt.grid()
plt.show()
