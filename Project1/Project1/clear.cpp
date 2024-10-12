#include "clear.h"
#include <iostream>

Cleaner::Cleaner() {}

void Cleaner::clearFullLines(Field& field) {
    int k = M - 1;
    for (int i = M - 1; i > 0; i--) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (field.getCell(j, i) != 0) count++;
        }
        if (count == N) {
            for (int j = 0; j < N; j++) {
                field.grid[k][j] = field.grid[i][j]; // Переносим строку вниз
            }
            k--;
        }
    }

    // Очищаем оставшиеся линии вверху
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < N; j++) {
            field.grid[i][j] = 0; // Устанавливаем оставшиеся линии в ноль
        }
    }
}

// Реализация метода draw
void Cleaner::draw() const {
    // Реализация отрисовки объекта
    std::cout << "Drawing Cleaner object" << std::endl;
}

// Реализация метода update
void Cleaner::update() {
    // Реализация обновления состояния объекта
}
