#include "figure.h"
#include "field.h"
#include <stdlib.h>

Point a[4], b[4];

bool check() {
    for (int i = 0; i < 4; i++) {
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return false; 
        if (Field::grid[a[i].y][a[i].x]) return false; 
    }
    return true;
}

void rotateFigure() {
    Point p = a[1];  // Ось вращения - центральная точка фигуры
    for (int i = 0; i < 4; i++) {
        int x = a[i].y - p.y;
        int y = a[i].x - p.x;
        a[i].x = p.x - x;
        a[i].y = p.y + y;
    }
    if (!check()) { 
        for (int i = 0; i < 4; i++) a[i] = b[i]; // Возврат, если поворот невалидный
    }
}

void generateNewFigure() {
    int n = rand() % 7; // Случайный выбор фигуры
    for (int i = 0; i < 4; i++) {
        a[i].x = Field::figures[n][i] % 2; // Координаты X
        a[i].y = Field::figures[n][i] / 2; // Координаты Y
    }
}


void placeFigure(int colorNum) {
    for (int i = 0; i < 4; i++) {
        Field::grid[a[i].y][a[i].x] = colorNum;  
    }
}
