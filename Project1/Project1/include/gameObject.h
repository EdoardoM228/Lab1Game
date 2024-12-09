#pragma once

/**
 * @class GameObject
 * @brief Базовый класс для всех игровых объектов.
 */
class GameObject {
public:
    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~GameObject() = default;

    /**
     * @brief Отображает объект на экране.
     */
    virtual void draw() const = 0;

    /**
     * @brief Обновляет состояние объекта.
     */
    virtual void update() = 0;
};
