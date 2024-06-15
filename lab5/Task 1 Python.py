# Импортируем необходимые библиотеки
import numpy as np
import matplotlib.pyplot as plt


# Функция для построения кубического сплайна
def cubic_spline(x, y):
    # Количество узлов
    n = len(x)
    # Копируем значения y в массив a
    a = y.copy()
    # Вычисляем расстояния между узлами
    h = [x[i + 1] - x[i] for i in range(n - 1)]

    # Инициализируем массив alpha
    alpha = [0] * (n - 1)
    # Вычисляем значения alpha
    for i in range(1, n - 1):
        alpha[i] = (3 / h[i]) * (a[i + 1] - a[i]) - (3 / h[i - 1]) * (a[i] - a[i - 1])

    # Инициализируем массивы l, mu и z
    l = [1] + [0] * (n - 1)
    mu = [0] * n
    z = [0] * n

    # Заполняем массивы l, mu и z для решения системы линейных уравнений
    for i in range(1, n - 1):
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i]

    # Устанавливаем граничные условия
    l[n - 1] = 1
    z[n - 1] = 0
    # Инициализируем массивы c, b и d
    c = [0] * n
    b = [0] * (n - 1)
    d = [0] * (n - 1)

    # Решаем систему уравнений методом обратной подстановки
    for j in range(n - 2, -1, -1):
        c[j] = z[j] - mu[j] * c[j + 1]
        b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3
        d[j] = (c[j + 1] - c[j]) / (3 * h[j])

    return a, b, c, d


# Функция для вычисления значения сплайна в заданной точке
def spline_value(x, a, b, c, d, x_star):
    # Количество узлов
    n = len(x)
    # Определяем интервал, в который попадает точка x_star
    for i in range(n - 1):
        if x[i] <= x_star <= x[i + 1]:
            dx = x_star - x[i]
            # Вычисляем значение сплайна в этой точке
            return a[i] + b[i] * dx + c[i] * dx ** 2 + d[i] * dx ** 3
    return None


# Заданные узлы интерполяции
x = [0.0, 1.0, 2.0, 3.0, 4.0]
y = [0.0, 0.5, 0.86603, 1.0, 0.86603]

# Построение кубического сплайна
a, b, c, d = cubic_spline(x, y)

# Вычисление значения функции в точке x* = 1.5
x_star = 1.5
result = spline_value(x, a, b, c, d, x_star)

# Выводим результат на экран
print(f"The value of the cubic spline at x* = {x_star} is: {result}")

# Построение графика
# Создаем массив точек для построения гладкой кривой сплайна
x_new = np.linspace(x[0], x[-1], 100)
# Вычисляем значения сплайна в этих точках
y_new = [spline_value(x, a, b, c, d, xi) for xi in x_new]

# Строим график исходных точек и кривой сплайна
plt.plot(x, y, 'o', label='Data points')
plt.plot(x_new, y_new, label='Cubic spline')
# Отмечаем точку x* = 1.5 на графике
plt.scatter([x_star], [result], color='red', zorder=5, label=f'Spline value at x* = {x_star}')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Cubic Spline Interpolation')
plt.grid(True)
# Показываем график
plt.show()
