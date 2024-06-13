#include <iostream>
#include <cmath>
#include <limits>

struct Line {
    double a;
    double b;
    double c;
};

struct Point {
    double x;
    double y;
};

// Функция для расчета расстояния от точки до прямой
double distancePointToLine(Line line, Point point) {
    return std::abs(line.a * point.x + line.b * point.y + line.c) / std::sqrt(line.a * line.a + line.b * line.b);
}

// Функция для нахождения точки пересечения двух прямых
Point intersectionPoint(Line line1, Line line2) {
    Point intersection;
    double determinant = line1.a * line2.b - line2.a * line1.b;
    if (determinant == 0) {
        std::cerr << "Прямые не пересекаются (они параллельны)." << std::endl;
        exit(1);
    } else {
        intersection.x = (line2.b * (-line1.c) - line1.b * (-line2.c)) / determinant;
        intersection.y = (line1.a * (-line2.c) - line2.a * (-line1.c)) / determinant;
    }
    return intersection;
}

// Функция для расчета угла между двумя прямыми
double angleBetweenLines(Line line1, Line line2) {
    double angle = std::atan(std::abs((line1.a * line2.b - line2.a * line1.b) / (line1.a * line2.a + line1.b * line2.b)));
    return angle * 180 / M_PI;
}

// Функция для проверки, являются ли две прямые параллельными
bool areLinesParallel(Line line1, Line line2) {
    return (line1.a * line2.b - line2.a * line1.b) == 0;
}

// Функция для расчета расстояния между параллельными прямыми
double distanceBetweenParallelLines(Line line1, Line line2) {
    return std::abs(line1.c - line2.c) / std::sqrt(line1.a * line1.a + line1.b * line1.b);
}

int main() {
    Line line1, line2;
    Point point;

    // Ввод параметров для первой прямой: a1x + b1y + c1 = 0
    std::cout << "Введите параметры для первой прямой (a1, b1, c1): ";
    std::cin >> line1.a >> line1.b >> line1.c;

    // Ввод параметров для второй прямой: a2x + b2y + c2 = 0
    std::cout << "Введите параметры для второй прямой (a2, b2, c2): ";
    std::cin >> line2.a >> line2.b >> line2.c;

    // Ввод координат точки (x, y)
    std::cout << "Введите координаты точки (x, y): ";
    std::cin >> point.x >> point.y;

    // Проверка, являются ли прямые параллельными
    if (areLinesParallel(line1, line2)) {
        std::cout << "Прямые параллельны." << std::endl;
        double distanceBetweenLines = distanceBetweenParallelLines(line1, line2);
        std::cout << "Расстояние между параллельными прямыми: " << distanceBetweenLines << std::endl;
    } else {
        std::cout << "Прямые не параллельны." << std::endl;

        // Нахождение точки пересечения двух прямых
        Point intersection = intersectionPoint(line1, line2);
        std::cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")" << std::endl;

        // Расчет расстояния от точки до точки пересечения
        double distanceToIntersection = std::sqrt((point.x - intersection.x) * (point.x - intersection.x) + (point.y - intersection.y) * (point.y - intersection.y));
        std::cout << "Расстояние от точки до точки пересечения: " << distanceToIntersection << std::endl;

        // Расчет угла между двумя прямыми
        double angle = angleBetweenLines(line1, line2);
        std::cout << "Угол между двумя прямыми: " << angle << " градусов" << std::endl;
    }

    // Расчет расстояния от точки до каждой прямой
    double distance1 = distancePointToLine(line1, point);
    double distance2 = distancePointToLine(line2, point);

    std::cout << "Расстояние от точки до первой прямой: " << distance1 << std::endl;
    std::cout << "Расстояние от точки до второй прямой: " << distance2 << std::endl;

    return 0;
}
