#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для вычисления интерполяционного многочлена Лагранжа
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double x_star) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x_star - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

// Функция для вычисления погрешности интерполяции
double interpolationError(double actual, double interpolated) {
    return fabs(actual - interpolated);
}

int main() {
    // Заданные точки интерполяции
    vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    vector<double> y(x.size());

    // Вычисление значений функции в заданных точках
    for (int i = 0; i < x.size(); i++) {
        y[i] = sin(x[i]);
    }

    // Точка, в которой вычисляется значение интерполяционного многочлена
    double x_star = 0.25 * M_PI;

    // Вычисление интерполяционного значения в точке x_star
    double interpolated_value = lagrangeInterpolation(x, y, x_star);

    // Точное значение функции в точке x_star
    double actual_value = sin(x_star);

    // Вычисление погрешности интерполяции
    double error = interpolationError(actual_value, interpolated_value);

    // Вывод результатов
    cout << "Interpolated value at x* = " << x_star << " is: " << interpolated_value << endl;
    cout << "Actual value at x* = " << x_star << " is: " << actual_value << endl;
    cout << "Interpolation error is: " << error << endl;

    return 0;
}
