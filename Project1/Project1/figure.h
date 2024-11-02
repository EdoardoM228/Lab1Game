#pragma once
#include "point.h"
#include <array>

extern std::array<Point, 4> a, b;

bool check();
void rotateFigure();
void generateNewFigure();
void placeFigure(int colorNum);
