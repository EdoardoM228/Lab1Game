/**
 * @file clear.cpp
 * @brief Реализация методов класса Cleaner для очистки заполненных линий.
 */

#include "clear.h"
#include <iostream>

/**
 * @brief Конструктор класса Cleaner.
 */
Cleaner::Cleaner() {}

/**
 * @brief Очищает полностью заполненные линии на игровом поле.
 * @param field Ссылка на объект игрового поля.
 */
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

/**
 * @brief Отрисовывает объект Cleaner.
 */
void Cleaner::draw() const {
    std::cout << "Drawing Cleaner object" << std::endl;
}

/**
 * @brief Обновляет состояние объекта Cleaner.
 */
void Cleaner::update() {
    // Реализация обновления состояния объекта
}
/**
 * @file clear.cpp
 * @brief Реализация методов класса Cleaner для очистки заполненных линий.
 */

#include "clear.h"
#include <iostream>

/**
 * @brief Конструктор класса Cleaner.
 */
Cleaner::Cleaner() {}

/**
 * @brief Очищает полностью заполненные линии на игровом поле.
 * @param field Ссылка на объект игрового поля.
 */
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

/**
 * @brief Отрисовывает объект Cleaner.
 */
void Cleaner::draw() const {
    std::cout << "Drawing Cleaner object" << std::endl;
}

/**
 * @brief Обновляет состояние объекта Cleaner.
 */
void Cleaner::update() {
    // Реализация обновления состояния объекта
}
