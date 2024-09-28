#include "figure.h"
#include "field.h"
#include <stdlib.h>

Point a[4], b[4];

bool check() {
    for (int i = 0; i < 4; i++) {
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0; 
        if (field[a[i].y][a[i].x]) return 0; 
    }
    return 1;
}

void rotateFigure() {
    Point p = a[1];  
    for (int i = 0; i < 4; i++) {
        int x = a[i].y - p.y;
        int y = a[i].x - p.x;
        a[i].x = p.x - x;
        a[i].y = p.y + y;
    }
    if (!check()) { 
        for (int i = 0; i < 4; i++) a[i] = b[i]; 
    }
}

void generateNewFigure() {
    int n = rand() % 7;
    for (int i = 0; i < 4; i++) {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
    }
}

void placeFigure(int colorNum) {
    for (int i = 0; i < 4; i++) {
        field[a[i].y][a[i].x] = colorNum;  // Поместить фигуру на поле с указанным цветом
    }
}
