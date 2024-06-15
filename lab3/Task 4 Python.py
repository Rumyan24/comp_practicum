from math import sin

# Функция для вычисления члена ряда
def term(k, x):
    return (-1) ** k / (sin(k * x) + 14 + k ** 2)

# Суммирование ряда до достижения заданной точности
def sum_series(x, eps=1e-6):
    sum_series = 0.0
    k = 1
    while True:
        t = term(k, x)
        sum_series += t
        if abs(t) < eps:
            break
        k += 1
    return sum_series, k

# Ввод значения x
x = float(input('Введите значение x: '))

# Вычисление суммы ряда с точностью до eps
eps = 1e-6
result, num_terms = sum_series(x, eps)

print(f'Сумма ряда: {result:.12f}')
print(f'Количество членов: {num_terms}')
