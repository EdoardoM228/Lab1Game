#include "figure.h"
#include "field.h"
#include <array>
#include <cstdlib>

std::array<Point, 4> a, b;

bool check() {
    for (const auto& p : a) {
        if (p.x < 0 || p.x >= N || p.y >= M || Field::grid[p.y][p.x] != 0) {
            return false;
        }
    }
    return true;
}

void rotateFigure() {
    Point p = a[1];
    for (auto& point : a) {
        int x = point.y - p.y;
        int y = point.x - p.x;
        point.x = p.x - x;
        point.y = p.y + y;
    }
    if (!check()) {
        a = b;
    }
}

void generateNewFigure() {
    int n = rand() % 7;
    for (int i = 0; i < 4; i++) {
        a[i].x = Field::figures[n][i] % 2;
        a[i].y = Field::figures[n][i] / 2;
    }
}

void placeFigure(int colorNum) {
    for (const auto& point : a) {
        Field::grid[point.y][point.x] = colorNum;
    }
}
