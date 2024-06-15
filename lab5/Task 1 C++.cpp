#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Функция для решения системы линейных уравнений методом Гаусса
void gaussElimination(int n, vector<vector<double>>& matrix, vector<double>& result) {
    for (int i = 0; i < n; ++i) {
        // Находим строку с максимальным элементом в текущем столбце для улучшения численной устойчивости
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Обмениваем строки
        for (int k = i; k < n + 1; ++k) {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        // Приводим матрицу к верхнетреугольному виду
        for (int k = i + 1; k < n; ++k) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; ++j) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }
    // Решаем систему уравнений методом обратной подстановки
    for (int i = n - 1; i >= 0; --i) {
        result[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            matrix[k][n] -= matrix[k][i] * result[i];
        }
    }
}

// Функция для вычисления коэффициентов кубического сплайна
void cubicSpline(int n, vector<double>& x, vector<double>& y, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    // Создаем матрицу и векторы для хранения промежуточных значений
    vector<vector<double>> matrix(n - 1, vector<double>(n, 0.0));
    vector<double> h(n), alpha(n - 1), l(n), mu(n), z(n);
    // Вычисляем расстояния между узлами
    for (int i = 0; i < n - 1; ++i) {
        h[i] = x[i + 1] - x[i];
    }
    // Вычисляем значения alpha
    for (int i = 1; i < n - 1; ++i) {
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);
    }
    l[0] = 1;
    mu[0] = z[0] = 0;
    // Заполняем матрицу для решения системы линейных уравнений
    for (int i = 1; i < n - 1; ++i) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n - 1] = 1;
    z[n - 1] = c[n - 1] = 0;
    // Решаем систему уравнений методом обратной подстановки
    for (int j = n - 2; j >= 0; --j) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
        a[j] = y[j];
    }
}

// Функция для вычисления значения сплайна в заданной точке
double splineValue(double x_star, vector<double>& x, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int n = x.size() - 1;
    int interval = 0;
    // Определяем интервал, в который попадает точка x_star
    for (int i = 0; i < n; ++i) {
        if (x_star >= x[i] && x_star <= x[i + 1]) {
            interval = i;
            break;
        }
    }
    double delta_x = x_star - x[interval];
    // Вычисляем значение сплайна в этой точке, используя коэффициенты a, b, c, d
    return a[interval] + b[interval] * delta_x + c[interval] * delta_x * delta_x + d[interval] * delta_x * delta_x * delta_x;
}

int main() {
    int n = 5;
    // Задаем координаты узлов x и значения функции в этих узлах y
    vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    vector<double> y = {0.0, 0.5, 0.86603, 1.0, 0.86603};
    // Создаем векторы для хранения коэффициентов сплайна
    vector<double> a(n), b(n), c(n), d(n);

    // Вызываем функцию для вычисления коэффициентов кубического сплайна
    cubicSpline(n, x, y, a, b, c, d);

    // Вычисляем значение сплайна в точке x_star = 1.5
    double x_star = 1.5;
    double result = splineValue(x_star, x, a, b, c, d);

    // Выводим результат на экран
    cout << "The value of the cubic spline at x* = " << x_star << " is: " << result << endl;

    return 0;
}
