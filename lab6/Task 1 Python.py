# Метод покоординатного спуска
# Запуск программы возможен в on-line компиляторе  https://www.codabrainy.com/en/python-compiler/

import numpy as np
import matplotlib.pyplot as plt

# Задаем параметры сетки
delta = 0.025
x = np.arange(-3.0, 3.0, delta)
y = np.arange(-3.0, 3.0, delta)
X, Y = np.meshgrid(x, y)


# Определяем функцию для оптимизации
def f(X, Y):
    return X ** 2 + 3 * Y ** 2 + np.cos(np.pi * (X + Y))


# Вычисляем значения функции на сетке
Z = f(X, Y)

# Начальная точка
x1, x2 = 1, 1

# Параметры алгоритма
alpha = 0.1
epsilon = 1e-6
max_iter = 100

# Списки для хранения траектории
x_history = [x1]
y_history = [x2]

# Алгоритм покоординатного спуска
for _ in range(max_iter):
    # Фиксируем x1, оптимизируем по x2
    grad_x2 = 6 * x2 - np.pi * np.sin(np.pi * (x1 + x2))
    x2_new = x2 - alpha * grad_x2
    # Фиксируем x2_new, оптимизируем по x1
    grad_x1 = 2 * x1 - np.pi * np.sin(np.pi * (x1 + x2_new))
    x1_new = x1 - alpha * grad_x1

    # Обновляем координаты
    x1, x2 = x1_new, x2_new

    # Сохраняем траекторию
    x_history.append(x1)
    y_history.append(x2)

    # Проверяем условие остановки
    if abs(grad_x1) < epsilon and abs(grad_x2) < epsilon:
        break

# Вывод результатов
print('Оптимальные значения:')
print('x1:', x1)
print('x2:', x2)
print('Минимальное значение функции:', f(x1, x2))

# Визуализация траектории
plt.contour(X, Y, Z)
plt.plot(x_history, y_history, 'r.-')
plt.title('Coordinate Descent')
plt.xlabel('x1')
plt.ylabel('x2')
plt.show()
