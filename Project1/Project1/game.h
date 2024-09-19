#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"

using namespace sf;

void handleInput(RenderWindow& window, int& dx, bool& rotate);
void updateGameState(RenderWindow& window, int& dx, bool& rotate, float& timer, float delay, int& colorNum);