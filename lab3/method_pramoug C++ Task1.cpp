#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

// Функция для интегрирования
double f(double x) {
    return pow(x, 4) * pow(14 + pow(x, 2), -1);
}

int main() {
    setlocale(LC_ALL, "rus");
    double a, b, x, h;
    int n_point;
    double sum = 0.0;

    // Задание пределов интегрирования
    a = 1.0;
    b = 2.0;

    // Задание числа точек (увеличьте для большей точности)
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


