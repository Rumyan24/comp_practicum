import math

# Функция для проверки, принадлежит ли точка гиперболе
def is_point_on_hyperbola(a, b, x, y):
    return abs((x**2 / a**2) - (y**2 / b**2) - 1) < 1e-6

# Ввод параметров гиперболы и координат точки
a = float(input("Введите значение a: "))
b = float(input("Введите значение b: "))
x = float(input("Введите координату x точки: "))
y = float(input("Введите координату y точки: "))

# Координаты фокусов гиперболы
c = math.sqrt(a**2 + b**2)
focus1 = (c, 0)
focus2 = (-c, 0)

# Длины действительной и мнимой полуосей
real_axis = 2 * a
imaginary_axis = 2 * b

# Эксцентриситет гиперболы
eccentricity = math.sqrt(1 + (b**2 / a**2))

# Расстояние между директрисами гиперболы
distance_between_directrices = 2 * a / math.sqrt(1 + (b**2 / a**2))

# Проверка принадлежности точки гиперболе
point_belongs = is_point_on_hyperbola(a, b, x, y)

print(f"Фокусы гиперболы: {focus1}, {focus2}")
print(f"Длина действительной полуоси: {real_axis / 2}")
print(f"Длина мнимой полуоси: {imaginary_axis / 2}")
print(f"Эксцентриситет гиперболы: {eccentricity}")
print(f"Расстояние между директрисами гиперболы: {distance_between_directrices}")
print(f"Точка ({x}, {y}) {'принадлежит' if point_belongs else 'не принадлежит'} гиперболе")
