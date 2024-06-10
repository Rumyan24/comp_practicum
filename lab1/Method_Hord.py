import math

def func(x):
    return 2.0 / (1.0 + x) - 3.0 * math.sin(x)

def chord_method(f, a, b, eps, max_iter):
    iteration = 0
    if f(a) * f(b) >= 0:
        return None

    x = a - (b - a) * f(a) / (f(b) - f(a))

    for _ in range(max_iter):
        if abs(f(x)) < eps:
            break

        if f(a) * f(x) < 0:
            b = x
        else:
            a = x

        x = a - (b - a) * f(a) / (f(b) - f(a))
        iteration += 1
    print(f"Количество итераций: {iteration}")
    return x

a = float(input("Введите левый край интервала a: "))  # левый край
b = float(input("Введите правый край интервала b: "))  # правый край
epsilon = 1e-6  # точность
max_iter = 1000

root = chord_method(func, a, b, epsilon, max_iter)
print(f"Корень уравнения: {root}")
fun = func(root)
print(f"Значение функции: f({root}) = {fun}")
