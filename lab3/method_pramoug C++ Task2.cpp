#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

// Функция для интегрирования
double f(double x) {
    return exp(-2*x) * sin(14*x);
}

int main() {
    setlocale(LC_ALL, "rus");
    double a, b, x, h;
    int n_point;
    double sum = 0.0;

    // Установка пределов интегрирования
    a = 0.0;
    b = 10.0;  // Используем большое значение в качестве верхнего предела

    // Установка числа точек
    n_point = 1000000;

    h = (b - a) / n_point;
    cout << "Величина шага h=" << fixed << setprecision(12) << h << endl;

    // Метод левых прямоугольников
    for (x = a; x < b; x += h) {
        sum += f(x);
    }
    sum *= h;

    cout << "Значение интеграла для метода левых прямоугольников:" << endl;
    cout << "I = " << sum << endl;

    return 0;
}
