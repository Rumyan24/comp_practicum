// Метод Ньютона
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return 2.0 / (1.0 + x) - 3.0 * sin(x);
}

double dfunc(double x)
{
    return -2.0 / ((1.0 + x) * (1.0 + x)) - 3.0 * cos(x);
}

double find(double x, double eps)
{
    double f, df;
    int iter = 0;
    cout << "x_0 = " << x << " ";
    do {
        f = func(x);
        df = dfunc(x);
        x = x - f / df;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    cout << "\nКоличество итераций = " << iter << endl;
    return x;
}

int main()
{
    double x0, x, eps;
    cout << "x_0 = ";
    cin >> x0;
    cout << "eps = ";
    cin >> eps;
    x = find(x0, eps);
    cout << "Корень x = " << fixed << setprecision(16) << x;
    cout << "\nЗначение функции f(x) = " << func(x);
    cin.get();
    return 0;
}
