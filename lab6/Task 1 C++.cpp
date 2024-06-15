// Метод покоординатного спуска
#define NMAX 100  // Максимальное количество итераций
#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

// Функция, которую оптимизируем
double f(double x, double y) {
    return (x * x + 3 * y * y + cos(M_PI * (x + y)));
}

// Производная по x
double f_dx(double x, double y) {
    return 2 * x - M_PI * sin(M_PI * (x + y));
}

// Производная по y
double f_dy(double x, double y) {
    return 6 * y - M_PI * sin(M_PI * (x + y));
}

// Половинный метод для нахождения минимального альфа
double Dihotomia(double a0, double b0, double epsilon, double x, double y)
{
    double lk, mk;
    double delta = 0.5 * epsilon;
    double ak = a0, bk = b0;

    do {
        lk = (ak + bk - delta) / 2;
        mk = (ak + bk + delta) / 2;

        if (f(x - lk * f_dx(x, y), y - lk * f_dy(x, y)) <= f(x - mk * f_dx(x, y), y - mk * f_dy(x, y))) {
            bk = mk;
        } else {
            ak = lk;
        }
    } while ((bk - ak) >= epsilon);

    return (ak + bk) / 2;
}

// Метод покоординатного спуска
double CoordinateDescent(double bx, double by, double epsilon)
{
    double x[NMAX];
    double y[NMAX];
    double alpha[NMAX];
    int k = 0;

    x[0] = bx;
    y[0] = by;

    cout << "Результаты:" << endl << "x(" << 0 << "): (" << x[0] << ", " << y[0] << ")" << endl;

    for (k = 0; ; k++) {
        alpha[k] = Dihotomia(-10000, 100000, epsilon, x[k], y[k]);
        x[k + 1] = x[k] - alpha[k] * f_dx(x[k], y[k]);
        y[k + 1] = y[k] - alpha[k] * f_dy(x[k], y[k]);

        cout << "x(" << k + 1 << "): " << "(" << x[k + 1] << ", " << y[k + 1] << ")" << endl
             << " f(" << x[k + 1] << ", " << y[k + 1] << ") = " << f(x[k + 1], y[k + 1]) << endl;

        if (k > 1 && sqrt(pow(x[k + 1] - x[k], 2) + pow(y[k + 1] - y[k], 2)) < epsilon) {
            break;
        }
    }

    cout << " \n Минимальная точка для (epsilon=" << epsilon << ") : \n"
         << "  f(x,y)= (" << x[k + 1] << ", " << y[k + 1] << ") = " << f(x[k + 1], y[k + 1]) <<"\n"<< endl;

    return f(x[k + 1], y[k + 1]);
}

int main() {
    double x, y, epsilon;
    cout << "Введите начальное значение x\n"; cin >> x;
    cout << "Введите начальное значение y\n"; cin >> y;
    cout << "Введите допустимую ошибку (epsilon=0.000001)\n"; cin >> epsilon;
    CoordinateDescent(x, y, epsilon);

    return 0;
}
