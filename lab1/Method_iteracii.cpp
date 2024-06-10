// Метод итераций
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return 2.0 / (1.0 + x) - 3.0 * sin(x);
}

double g(double x)
{
    // Преобразуем исходное уравнение для метода итераций.
    // Пусть g(x) = x - k * (2 / (1 + x) - 3 * sin(x)), где k - произвольный параметр
    // Здесь мы выберем k = 0.1 для простоты.
    return x - 0.1 * (2.0 / (1.0 + x) - 3.0 * sin(x));
}

double find(double x, double eps)
{
    double x_1, x_2;
    int iter = 0;
    x_2 = x;
    do {
        x_1 = x_2;
        x_2 = g(x_1);
        cout << x_2 << "\n";
        iter++;
    } while (fabs(x_2 - x_1) > eps && iter < 20000);
    cout <<"\nКоличество итераций = " << iter << endl;
    return x_2;
}

int main()
{
    double x0, eps, root;
    cout << "x_0 = ";
    cin >> x0;
    cout << "eps = ";
    cin >> eps;
    root = find(x0, eps);
    cout <<"Корень x = "<< fixed << setprecision(16) << root;
    cout <<"\nЗначение функции f(x) = "<< func(root);
    cin.get();
    return 0;
}
