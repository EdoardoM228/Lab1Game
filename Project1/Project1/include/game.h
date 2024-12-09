#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"
#include "gameObject.h"
#include "figure.h"
#include <ostream>

using namespace sf;

/**
 * @class Game
 * @brief Основной игровой цикл.
 * @details Управляет игровым процессом, включая ввод, обновление состояния и отрисовку.
 */
class Game : public GameObject {
public:
    int dx;         ///< Движение фигуры по оси X.
    bool rotate;    ///< Флаг, указывающий на необходимость поворота фигуры.
    float timer;    ///< Таймер для управления движением.
    float delay;    ///< Задержка для обновления игры.
    int colorNum;   ///< Номер текущего цвета фигуры.

    /**
     * @brief Конструктор по умолчанию.
     */
    Game();

    /**
     * @brief Обрабатывает ввод с клавиатуры.
     * @param window Окно приложения.
     */
    void handleInput(RenderWindow& window);

    /**
     * @brief Обновляет состояние игры.
     * @param window Окно приложения.
     */
    void updateGameState(RenderWindow& window);

    /**
     * @brief Отображает текущую игру.
     */
    void draw() const override;

    /**
     * @brief Обновляет игровое состояние.
     */
    void update() override;

    /**
     * @brief Перегруженный оператор вывода.
     * @param os Поток вывода.
     * @param game Объект игры.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
