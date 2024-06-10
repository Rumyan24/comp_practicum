from math import sin, cos

def func(x):
    return 2.0 / (1.0 + x) - 3.0 * sin(x)

def g(x):
    # Преобразуем исходное уравнение для метода итераций.
    # Пусть g(x) = x - k * (2 / (1 + x) - 3 * sin(x)), где k - произвольный параметр
    # Здесь мы выберем k = 0.1 для простоты.
    return x - 0.1 * func(x)

def simple_iteration_method(x_0, epsilon):
    x = x_0
    iter = 0
    while True:
        x_new = g(x)
        if abs(x_new - x) < epsilon:
            print(f"Количество итераций: {iter}")
            return x_new
        x = x_new
        iter += 1

x_0 = float(input("Введите начальное значение x_0: "))  # начальное значение
epsilon = 1e-6  # точность

root = simple_iteration_method(x_0, epsilon)
print(f"Решение уравнения: x = {root}")
fun = func(root)
print(f"Значение функции: f({root}) = {fun}")
