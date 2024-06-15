#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// Функция для интегрирования
double f(double x) {
    return exp(-2 * x) * sin(14 * x);
}

// Функция вычисления определенного интеграла методом трапеций
double Integral(double *f, double step, int n) {
    double sum = 0.0;
    sum = 0.5 * (f[0] + f[n-1]);
    for (int i = 1; i < n-1; i++) {
        sum += f[i];
    }
    sum *= step;
    return sum;
}

int main() {
    setlocale(LC_ALL, "rus");
    double *f_values;
    double a, b;
    double step, x;
    double sum = 0.0;
    int n_point;

    cout << "Введите нижний предел a=";
    cin >> a;
    cout << "Введите верхний предел b=";
    cin >> b;
    cout << "Введите число точек n=";
    cin >> n_point;

    f_values = (double*)malloc(n_point * sizeof(double));
    step = (b - a) / n_point; // величина шага (высота трапеций)
    cout << "Величина шага h=" << fixed << setprecision(12) << step << endl;

    x = a;
    // Инициализация значений функции f(x)
    for (int i = 0; i < n_point; i++) {
        f_values[i] = f(x);
        x += step;
    }

    sum = Integral(f_values, step, n_point); // вычисление интеграла
    cout << "Значение интеграла I=" << fixed << setprecision(12) << sum << endl;

    free(f_values); // освобождение выделенной памяти

    return 0;
}
