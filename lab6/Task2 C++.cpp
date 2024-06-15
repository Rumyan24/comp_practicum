#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Определяем функцию для оптимизации
double f(double x1, double x2) {
    return 7*x1*x1 + 2*x1*x2 + 5*x2*x2 + x1 - 10*x2;
}

// Определяем градиенты функции
void gradient(double x1, double x2, double& grad_x1, double& grad_x2) {
    grad_x1 = 14*x1 + 2*x2 + 1;
    grad_x2 = 2*x1 + 10*x2 - 10;
}

int main() {
    // Начальная точка
    double x1 = 0.0, x2 = 0.0;
    // Параметры алгоритма
    double alpha = 0.01;
    double epsilon = 1e-6;
    int max_iter = 1000;

    vector<pair<double, double>> trajectory;
    trajectory.push_back({x1, x2});

    // Алгоритм наискорейшего спуска
    for (int iter = 0; iter < max_iter; ++iter) {
        double grad_x1, grad_x2;
        gradient(x1, x2, grad_x1, grad_x2);

        // Обновляем значения
        x1 = x1 - alpha * grad_x1;
        x2 = x2 - alpha * grad_x2;

        trajectory.push_back({x1, x2});

        // Проверка условия остановки
        if (sqrt(grad_x1*grad_x1 + grad_x2*grad_x2) < epsilon) {
            break;
        }
    }

    // Вывод результатов
    cout << "Оптимальные значения:" << endl;
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;
    cout << "Минимальное значение функции: " << f(x1, x2) << endl;

    return 0;
}
