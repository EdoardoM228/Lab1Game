#pragma once
#include <ostream>

const int M = 20;
const int N = 10;

class Field {
 public:
    static int grid[M][N];
    static int figures[7][4]; // Объявление массива фигур
    Field(); // Конструктор
    Field(const Field& other); // Оператор копирования
    Field& operator=(const Field& other); // Оператор присваивания

    // Метод для получения ячейки
    int getCell(int x, int y) const;

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};
