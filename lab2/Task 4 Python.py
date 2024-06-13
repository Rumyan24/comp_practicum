import math

# Функция для проверки, принадлежит ли точка однополостному гиперболоиду
def is_point_on_hyperboloid(a, b, c, x, y, z):
    return abs((x**2 / a**2) + (y**2 / b**2) - (z**2 / c**2) - 1) < 1e-6

# Функция для проверки пересечения плоскости с гиперболоидом
def does_plane_intersect_hyperboloid(a, b, c, d):
    return a != 0 or b != 0 or c != 0

# Ввод параметров гиперболоида и координат точки
a = float(input("Введите значение a: "))
b = float(input("Введите значение b: "))
c = float(input("Введите значение c: "))
x = float(input("Введите координату x точки: "))
y = float(input("Введите координату y точки: "))
z = float(input("Введите координату z точки: "))

# Ввод параметров плоскости: Ax + By + Cz + D = 0
A = float(input("Введите коэффициент A для плоскости: "))
B = float(input("Введите коэффициент B для плоскости: "))
C = float(input("Введите коэффициент C для плоскости: "))
D = float(input("Введите коэффициент D для плоскости: "))

# Проверка пересечения плоскости с гиперболоидом
plane_intersects = does_plane_intersect_hyperboloid(A, B, C, D)

# Проверка принадлежности точки гиперболоиду
point_belongs = is_point_on_hyperboloid(a, b, c, x, y, z)

print(f"Плоскость {'пересекает' if plane_intersects else 'не пересекает'} гиперболоид")
print(f"Точка ({x}, {y}, {z}) {'принадлежит' if point_belongs else 'не принадлежит'} гиперболоиду")
