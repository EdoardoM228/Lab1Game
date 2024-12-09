#pragma once
#include <ostream>

/**
 * @struct Point
 * @brief Структура для представления точки на плоскости.
 */
struct Point {
    int x; ///< Координата X.
    int y; ///< Координата Y.

    /**
     * @brief Конструктор точки.
     * @param x Координата X (по умолчанию 0).
     * @param y Координата Y (по умолчанию 0).
     */
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    /**
     * @brief Оператор сравнения.
     * @param other Другая точка.
     * @return true, если точки равны.
     */
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    /**
     * @brief Оператор вывода.
     * @param os Поток вывода.
     * @param point Точка.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        return os << "(" << point.x << ", " << point.y << ")";
    }
};
