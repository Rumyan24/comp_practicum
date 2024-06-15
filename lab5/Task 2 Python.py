import numpy as np
import math


# Функция для вычисления интерполяционного многочлена Лагранжа
def lagrange_interpolation(x, y, x_star):
    result = 0.0
    n = len(x)

    for i in range(n):
        term = y[i]
        for j in range(n):
            if j != i:
                term *= (x_star - x[j]) / (x[i] - x[j])
        result += term

    return result


# Функция для вычисления погрешности интерполяции
def interpolation_error(actual, interpolated):
    return abs(actual - interpolated)


# Заданные точки интерполяции
x = [0.1 * math.pi, 0.2 * math.pi, 0.3 * math.pi, 0.4 * math.pi]
y = [math.sin(xi) for xi in x]

# Точка, в которой вычисляется значение интерполяционного многочлена
x_star = 0.25 * math.pi

# Вычисление интерполяционного значения в точке x_star
interpolated_value = lagrange_interpolation(x, y, x_star)

# Точное значение функции в точке x_star
actual_value = math.sin(x_star)

# Вычисление погрешности интерполяции
error = interpolation_error(actual_value, interpolated_value)

# Вывод результатов
print(f"Interpolated value at x* = {x_star} is: {interpolated_value}")
print(f"Actual value at x* = {x_star} is: {actual_value}")
print(f"Interpolation error is: {error}")
