#pragma once

class GameObject {
public:
    virtual ~GameObject() = default; // Виртуальный деструктор

    // Чисто виртуальные функции для дальнейшей реализации
    virtual void draw() const = 0;
    virtual void update() = 0;
};
