/**
 * @file field.cpp
 * @brief Реализация методов класса Field для управления игровым полем.
 */

#include "field.h"
#include <algorithm> // для std::fill

/**
 * @brief Статический двумерный вектор для хранения состояния игрового поля.
 */
std::vector<std::vector<int>> Field::grid(M, std::vector<int>(N, 0));

/**
 * @brief Статический вектор фигур для игры.
 */
std::vector<std::vector<int>> Field::figures = {
    {1, 3, 5, 7},  {2, 4, 5, 7},  {3, 5, 4, 6},
    {3, 5, 4, 7},  {2, 3, 5, 7},  {3, 5, 7, 6},
    {2, 3, 4, 5}
};

/**
 * @brief Конструктор класса Field.
 */
Field::Field() {}

/**
 * @brief Оператор присваивания для класса Field.
 * @param other Другой объект Field для копирования.
 * @return Ссылка на текущий объект.
 */
Field& Field::operator=(const Field& other) {
    if (this != &other) {
        grid = other.grid;
        figures = other.figures;
    }
    return *this;
}

/**
 * @brief Получает значение ячейки игрового поля.
 * @param x Координата X ячейки.
 * @param y Координата Y ячейки.
 * @return Значение ячейки.
 */
int Field::getCell(int x, int y) const {
    return grid[y][x];
}

/**
 * @brief Оператор вывода для класса Field.
 * @param os Поток вывода.
 * @param field Объект игрового поля.
 * @return Поток вывода.
 */
std::ostream& operator<<(std::ostream& os, const Field& field) {
    for (const auto& row : Field::grid) {
        for (const auto& cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
    return os;
}
