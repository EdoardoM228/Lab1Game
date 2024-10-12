#include "game.h"
#include "figure.h"
#include "clear.h"
#include "field.h"
#include <iostream>

Game::Game() : dx(0), rotate(false), timer(0), delay(0.3), colorNum(1) {}

void Game::handleInput(RenderWindow& window) {
    dx = 0;  
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed)
            window.close();
        if (e.type == Event::KeyPressed) {
            if (e.key.code == Keyboard::Up)
                rotate = true;  
            else if (e.key.code == Keyboard::Left)
                dx = -1;  
            else if (e.key.code == Keyboard::Right)
                dx = 1; 
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
            for (int i = 0; i < 4; i++)
                Field::grid[b[i].y][b[i].x] = colorNum;  
            generateNewFigure(); 
            colorNum = 1 + rand() % 7;  
        }

        timer = 0;  
    }

    dx = 0;
}

// Реализация метода draw
void Game::draw() const {
    // Реализация отрисовки объекта
    std::cout << "Drawing Game object" << std::endl;
}

// Реализация метода update
void Game::update() {
    // Реализация обновления состояния объекта
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game State: dx=" << game.dx << ", rotate=" << game.rotate 
       << ", timer=" << game.timer << ", delay=" << game.delay 
       << ", colorNum=" << game.colorNum;
    return os;
}
