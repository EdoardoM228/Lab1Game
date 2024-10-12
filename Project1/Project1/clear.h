#pragma once
#include "field.h"
#include "gameObject.h"

class Cleaner : public GameObject {
public:
    Cleaner(); // Конструктор

    // Реализация методов базового класса
    void clearFullLines(Field& field); 
    void draw() const override; // Реализация метода draw
    void update() override; // Реализация обновления состояния
};
