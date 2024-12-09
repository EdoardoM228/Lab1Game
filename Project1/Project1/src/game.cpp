/**
 * @file game.cpp
 * @brief Реализация методов класса Game для игрового процесса.
 */

#include "game.h"
#include "figure.h"
#include "clear.h"
#include "field.h"
#include <iostream>
#include <memory>

/**
 * @brief Конструктор класса Game.
 */
Game::Game() : dx(0), rotate(false), timer(0), delay(0.3), colorNum(1) {}

/**
 * @brief Обрабатывает пользовательский ввод.
 * @param window Ссылка на окно SFML.
 */
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

/**
 * @brief Обновляет состояние игры.
 * @param window Ссылка на окно SFML.
 */
void Game::updateGameState(RenderWindow& window) {
    // Логика обновления состояния
}

/**
 * @brief Отрисовывает объект Game.
 */
void Game::draw() const {
    std::cout << "Drawing Game object" << std::endl;
}

/**
 * @brief Обновляет состояние объекта Game.
 */
void Game::update() {
    // Логика обновления
}

/**
 * @brief Оператор вывода состояния игры.
 */
std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game State: dx=" << game.dx << ", rotate=" << game.rotate
       << ", timer=" << game.timer << ", delay=" << game.delay
       << ", colorNum=" << game.colorNum;
    return os;
}
