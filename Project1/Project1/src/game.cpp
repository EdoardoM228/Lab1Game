#include "game.h"
#include "figure.h"
#include "clear.h"
#include "field.h"
#include <iostream>
#include <memory> // Для использования умных указателей

Game::Game() : dx(0), rotate(false), timer(0), delay(0.3), colorNum(1) {}

void Game::handleInput(RenderWindow& window) {
    dx = 0;
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed)
            window.close();
        if (e.type == Event::KeyPressed) {
            switch (e.key.code) {
                case Keyboard::Up:
                    rotate = true;
                    break;
                case Keyboard::Left:
                    dx = -1;
                    break;
                case Keyboard::Right:
                    dx = 1;
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::updateGameState(RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        b[i] = a[i];
        a[i].x += dx;
    }
    if (!check())
        for (int i = 0; i < 4; i++)
            a[i] = b[i];

    if (rotate) {
        rotateFigure();
        rotate = false;
    }

    if (timer > delay) {
        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
            a[i].y += 1;
        }

        if (!check()) {
            for (const auto& point : b) {
                Field::grid[point.y][point.x] = colorNum;
            }
            generateNewFigure();
            colorNum = 1 + rand() % 7;
        }

        timer = 0;
    }

    dx = 0;
}

void Game::draw() const {
    std::cout << "Drawing Game object" << std::endl;
}

void Game::update() {
    // Логика обновления состояния объекта
}


std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game State: dx=" << game.dx << ", rotate=" << game.rotate
       << ", timer=" << game.timer << ", delay=" << game.delay
       << ", colorNum=" << game.colorNum;
    return os;
}
