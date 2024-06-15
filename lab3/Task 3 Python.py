# Сумма числового ряда с заданной точностью
eps = 1e-6
sum_series = 0.0
k = 1

while True:
    term = 14 / (2 ** (k - 1)) + ((-1) ** (k - 1)) / (2 * (3 ** (k - 1)))
    sum_series += term
    
    if abs(term) < eps:
        break
    
    k += 1

print(f'Сумма ряда: {sum_series:.12f}')
print(f'Количество членов: {k}')
