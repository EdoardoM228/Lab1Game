#pragma once
#include <ostream>

struct Point {
    int x, y;

    // Конструктор
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Оператор сравнения
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        return os << "(" << point.x << ", " << point.y << ")";
    }
};
