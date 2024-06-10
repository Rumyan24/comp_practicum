import math

def func(x):
    return 2.0 / (1.0 + x) - 3.0 * math.sin(x)

def derivative_func(x):
    return -2.0 / ((1.0 + x) * (1.0 + x)) - 3.0 * math.cos(x)

def tangent_method(f, df, x0, epsilon, max_iter):
    x = x0
    for i in range(max_iter):
        f_x = f(x)
        f_derivative = df(x)
        x_new = x - f_x / f_derivative

        if abs(x_new - x) < epsilon:
            return x_new, i + 1
        x = x_new

    return None, max_iter

x0 = float(input("Введите начальное значение x0: "))  # начальное значение
epsilon = 1e-6  # точность
max_iter = 100  # максимальное число итераций

root, iterations = tangent_method(func, derivative_func, x0, epsilon, max_iter)

print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun = func(root)
print(f"Значение функции: f({root}) = {fun}")
