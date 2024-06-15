#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 4 // Обновлено для системы 4 на 4
#define N1 N+1
using namespace std;

/* Определение матрицы системы */
float matrix[N][N1] = {
    {-9, 8, 8, 6, -81},
    {-7, -9, 5, 4, -50},
    {-3, -1, 8, 0, -69},
    {3, -1, -4, -5, 48}
};

/* Точность вычислений */
float epsilon = 0.001;

void ShowMatrix() {
    cout << "СЛАУ Гаусс:" << endl;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%+3.3f*x%d ", matrix[i][j], j + 1);
        printf("= %3.3f\n", matrix[i][N]);
    }
}

int main() {
    float tmp, xx[N];
    short int i, j, k;

    ShowMatrix();

    /* Метод Гаусса */
    /* Прямой ход */
    for (i = 0; i < N; i++) {
        tmp = matrix[i][i];
        for (j = N; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < N; j++) {
            tmp = matrix[j][i];
            for (k = N; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }

    /* Обратный ход */
    xx[N - 1] = matrix[N - 1][N];
    for (i = N - 2; i >= 0; i--) {
        xx[i] = matrix[i][N];
        for (j = i + 1; j < N; j++)
            xx[i] -= matrix[i][j] * xx[j];
    }

    /* Вывод решения */
    printf("\nМетод Гаусса:\n");
    for (i = 0; i < N; i++)
        printf("x[%d] = %6.5f\n", i + 1, xx[i]);

    return 0;
}

