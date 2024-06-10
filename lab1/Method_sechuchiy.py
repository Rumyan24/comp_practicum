import math

def func(x):
    return 2.0 / (1.0 + x) - 3.0 * math.sin(x)

def secant_method(f, x_0, x_1, epsilon, max_iter):
    iteration = 0

    while iteration < max_iter:
        x_2 = x_1 - f(x_1) * (x_1 - x_0) / (f(x_1) - f(x_0))

        if abs(x_2 - x_1) < epsilon:
            return x_2, iteration

        x_0 = x_1
        x_1 = x_2
        iteration += 1

    raise Exception("Не удалось найти корень методом секущих")

x_0 = float(input("Введите начальное значение x_0: "))  # начальное значение x_0
x_1 = float(input("Введите начальное значение x_1: "))  # начальное значение x_1
epsilon = 1e-6  # точность
max_iter = 100  # максимальное число итераций

root, iterations = secant_method(func, x_0, x_1, epsilon, max_iter)
print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun = func(root)
print(f"Значение функции: f({root}) = {fun}")
