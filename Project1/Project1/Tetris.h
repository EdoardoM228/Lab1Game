#ifndef TETRIS_H
#define TETRIS_H

#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 20;
const int N = 10;

extern int field[M][N];

struct Point {
    int x, y;
};

extern Point a[4], b[4];
extern int figures[7][4];

bool check();
void placeFigure(int colorNum);
void clearFullLines();
void rotateFigure();
void generateNewFigure();
void handleInput(RenderWindow& window, int& dx, bool& rotate);
void updateGameState(RenderWindow& window, int& dx, bool& rotate, float& timer, float delay, int& colorNum);

#endif // TETRIS_H
