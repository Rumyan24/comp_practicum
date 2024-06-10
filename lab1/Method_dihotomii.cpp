// Метод Дихотомии
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return 2.0 / (1.0 + x) - 3.0 * sin(x);
}

int main()
{
    int iter = 0;
    double eps = 1e-6;
    double a, b, t, f1, f2, x;

    cout << "Введите отрезок, на котором предполагается нахождение корня уравнения!" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;


    do
    {
        f1 = func(a);
        t = (a + b) / 2.0;
        f2 = func(t);
        if (f1 * f2 <= 0) b = t;
        else a = t;
        iter++;
    } while (fabs(b - a) > eps);

    x = (a + b) / 2.0;
    f1 = func(x);
    if (fabs(f1) <= eps)
    {
        cout << "\nКорень уравнения с ошибкой ";
        cout << fixed << setprecision(16) << "eps = " << eps << " равен x = " << x;
        cout << "\nЗначение функции f(x) = " << func(x) << ".";
        cout << "\nКоличество итераций = " << iter << ".";
    }
    else
        cout << "На этом отрезке уравнение не имеет корней";

    return 0;
}
