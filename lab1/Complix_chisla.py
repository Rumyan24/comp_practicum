import cmath

# Даны комплексные числа
z1 = 1 + 1j
z2 = 1 + 2j
z3 = 1 + 1j

# Сумма
sum_result = z1 + z2
print(f"Сумма: {z1} + {z2} = {sum_result}")

# Разность
difference_result = z1 - z2
print(f"Разность: {z1} - {z2} = {difference_result}")

# Произведение
product_result = z1 * z2
print(f"Произведение: {z1} * {z2} = {product_result}")

# Частное
quotient_result = z1 / z2
print(f"Частное: {z1} / {z2} = {quotient_result}")

# Четвёртая степень
fourth_power_result = z3 ** 4
print(f"Четвёртая степень: ({z3})^4 = {fourth_power_result}")

# Кубический корень
cube_root_result = z3 ** (1/3)
print(f"Кубический корень: ({z3})^(1/3) = {cube_root_result}")
