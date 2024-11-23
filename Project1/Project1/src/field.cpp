#include "field.h"
#include <algorithm> // для std::fill

// Инициализация статического двумерного вектора grid
std::vector<std::vector<int>> Field::grid(M, std::vector<int>(N, 0)); // Все элементы инициализированы нулями

// Инициализация статического вектора figures
std::vector<std::vector<int>> Field::figures = {
    {1, 3, 5, 7},  // Фигура 1
    {2, 4, 5, 7},  // Фигура 2
    {3, 5, 4, 6},  // Фигура 3
    {3, 5, 4, 7},  // Фигура 4
    {2, 3, 5, 7},  // Фигура 5
    {3, 5, 7, 6},  // Фигура 6
    {2, 3, 4, 5}   // Фигура 7
};

Field::Field() {
    // Конструктор не требует дополнительной инициализации для grid, так как она уже инициализирована выше
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        grid = other.grid; // Копирование вектора
        figures = other.figures; // Копирование фигур
    }
    return *this;
}

int Field::getCell(int x, int y) const {
    return grid[y][x];
}

std::ostream& operator<<(std::ostream& os, const Field& field) {
    for (const auto& row : Field::grid) {
        for (const auto& cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
    return os;
}