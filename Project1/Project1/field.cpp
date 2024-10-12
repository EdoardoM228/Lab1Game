#include "field.h"
#include <cstring> // Для memcpy

Field::Field() {
    std::memset(grid, 0, sizeof(grid)); // Инициализация поля нулями
}

int Field::figures[7][4] = {
    1, 3, 5, 7,  // Фигура 1
    2, 4, 5, 7,  // Фигура 2
    3, 5, 4, 6,  // Фигура 3
    3, 5, 4, 7,  // Фигура 4
    2, 3, 5, 7,  // Фигура 5
    3, 5, 7, 6,  // Фигура 6
    2, 3, 4, 5   // Фигура 7
};

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        std::memcpy(grid, other.grid, sizeof(grid)); // Копирование массива
    }
    return *this;
}

int Field::getCell(int x, int y) const {
    return grid[y][x];
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Field& field) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            os << field.grid[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
