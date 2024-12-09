#pragma once
#include "field.h"
#include "gameObject.h"

/**
 * @class Cleaner
 * @brief Класс для очистки поля от заполненных линий.
 * @details Реализует функциональность очистки полных линий на игровом поле.
 */
class Cleaner : public GameObject {
public:
    /**
     * @brief Конструктор класса Cleaner.
     */
    Cleaner();

    /**
     * @brief Очищает заполненные линии на игровом поле.
     * @param field Игровое поле.
     */
    void clearFullLines(Field& field);

    /**
     * @brief Отображает объект Cleaner на экране.
     */
    void draw() const override;

    /**
     * @brief Обновляет состояние объекта Cleaner.
     */
    void update() override;
};
