import numpy

M4 = numpy.array([
    [-9., 8., 8., 6.],
    [-7., -9., 5., 4.],
    [-3., -1., 8., 0.],
    [3., -1., -4., -5.]
])

v4 = numpy.array([-81., -50., -69., 48])

a = numpy.linalg.solve(M4, v4)

print('Решение СЛАУ')
print(a)
