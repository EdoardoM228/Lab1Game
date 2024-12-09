#pragma once
#include "point.h"
#include <array>

extern std::array<Point, 4> a, b; ///< Координаты текущей и следующей фигуры.

/**
 * @brief Проверяет валидность текущей фигуры.
 * @return true, если фигура валидна.
 */
bool check();

/**
 * @brief Выполняет поворот текущей фигуры.
 */
void rotateFigure();

/**
 * @brief Генерирует новую фигуру.
 */
void generateNewFigure();

/**
 * @brief Размещает текущую фигуру на игровом поле.
 * @param colorNum Номер цвета фигуры.
 */
void placeFigure(int colorNum);
