#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf; // Используем пространство имен SFML
using namespace std; // Если нужно, используем пространство имен std

int main() {
    RenderWindow window(VideoMode(320, 480), "Tetris");
    Game game; // Создание объекта Game

    // Основной игровой цикл
    while (window.isOpen()) {
        game.handleInput(window); // Обработка ввода
        game.updateGameState(window); // Обновление состояния игры
        window.clear(Color::White); // Очистка окна
        game.draw(); // Отрисовка состояния игры
        window.display(); // Обновление окна
    }

    return 0;
}
