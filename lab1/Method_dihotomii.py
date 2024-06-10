import math

def func(x):
    return 2.0 / (1.0 + x) - 3.0 * math.sin(x)

def dichotomy_method(f, a, b, epsilon):
    if f(a) * f(b) > 0:
        return None
    iter = 0
    while (b - a) / 2 > epsilon:
        c = (a + b) / 2
        iter += 1
        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    print(f"Количество итераций: {iter}") 
    return (a + b) / 2

a = float(input("Введите левый край интервала a: "))
b = float(input("Введите правый край интервала b: "))
epsilon = 1e-6  # точность

root = dichotomy_method(func, a, b, epsilon)
print(f"Решение уравнения: x = {root}")
fun = func(root)
print(f"Значение функции: f({root}) = {fun}")
