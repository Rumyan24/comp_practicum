#include <iostream>
#include <complex>
#include <cmath>

int main() {
    // Определение комплексных чисел
    std::complex<double> z1(1, 1); // 1 + i
    std::complex<double> z2(1, 2); // 1 + 2i
    std::complex<double> z3(1, 1); // 1 + i

    // Выполнение операций
    auto sum_z1_z2 = z1 + z2;
    auto difference_z1_z2 = z1 - z2;
    auto product_z1_z2 = z1 * z2;
    auto quotient_z1_z2 = z1 / z2;

    // Вычисление четвертой степени и кубического корня z3
    auto fourth_power_z3 = std::pow(z3, 4);
    auto cube_root_z3 = std::pow(z3, 1.0 / 3.0);

    // Вывод результатов
    std::cout << "Сумма: " << sum_z1_z2 << std::endl;
    std::cout << "Разность: " << difference_z1_z2 << std::endl;
    std::cout << "Произведение: " << product_z1_z2 << std::endl;
    std::cout << "Частное: " << quotient_z1_z2 << std::endl;
    std::cout << "Четвертая степень z3: " << fourth_power_z3 << std::endl;
    std::cout << "Кубический корень z3: " << cube_root_z3 << std::endl;

    return 0;
}
