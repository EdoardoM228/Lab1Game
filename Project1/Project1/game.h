#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"
#include "gameObject.h"
#include <ostream>

using namespace sf;

class Game : public GameObject {
public:
    int dx;         // Движение по оси X
    bool rotate;    // Флаг поворота
    float timer;    // Таймер
    float delay;    // Задержка
    int colorNum;   // Цвет фигуры

    Game();

    void handleInput(RenderWindow& window);
    void updateGameState(RenderWindow& window);
    void draw() const override;
    void update() override;

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
