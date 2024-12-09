/**
 * @file main.cpp
 * @brief Точка входа в игру "Тетрис".
 */

#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf;
using namespace std;

/**
 * @brief Основная функция программы.
 * @return Код завершения.
 */
int main() {
    RenderWindow window(VideoMode(320, 480), "Tetris");
    Game game;

    while (window.isOpen()) {
        game.handleInput(window);
        game.updateGameState(window);
        window.clear(Color::White);
        game.draw();
        window.display();
    }

    return 0;
}
