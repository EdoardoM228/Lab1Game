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
            std::copy(field.grid[i].begin(), field.grid[i].end(), field.grid[k].begin());
            k--;
        }
    }

    // Очищаем оставшиеся линии вверху
    for (int i = 0; i <= k; i++) {
        std::fill(field.grid[i].begin(), field.grid[i].end(), 0);
    }
}

void Cleaner::draw() const {
    std::cout << "Drawing Cleaner object" << std::endl;
}

void Cleaner::update() {
    // Реализация обновления состояния объекта
}
