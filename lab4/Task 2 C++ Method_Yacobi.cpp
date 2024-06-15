#include <iostream>
#include <cmath>
using namespace std;

const int N = 3;  // Размерность системы

void multiply(double A[N][N], double B[N], double C[N]) {
    for (int i = 0; i < N; i++) {
        C[i] = 0;
        for (int j = 0; j < N; j++) {
            C[i] += A[i][j] * B[j];
        }
    }
}

int main() {
    double A[N][N] = {
        {5, 2, -2},
        {3, -3, -1},
        {2, 3, -1}
    };
    double b[N] = {0, 1, -1};
    double x[N] = {0, 0, 0};  // Начальное приближение
    double x_new[N] = {0, 0, 0};  // Новое приближение
    double Dinv[N][N] = {0};
    double R[N][N] = {0};

    // Заполняем Dinv и R
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                Dinv[i][j] = 1.0 / A[i][j];
            } else {
                R[i][j] = A[i][j];
            }
        }
    }

    int iter;
    cout << "Введите число итераций: ";
    cin >> iter;

    for (int k = 0; k < iter; k++) {
        double temp[N] = {0};
        multiply(R, x, temp);
        for (int i = 0; i < N; i++) {
            x_new[i] = Dinv[i][i] * (b[i] - temp[i]);
        }

        for (int i = 0; i < N; i++) {
            x[i] = x_new[i];
        }

        cout << "Итерация #" << k + 1 << ": ";
        for (int i = 0; i < N; i++) {
            cout << "x" << i + 1 << " = " << x[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
