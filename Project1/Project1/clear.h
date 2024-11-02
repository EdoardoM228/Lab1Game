#pragma once
#include "field.h"
#include "gameObject.h"

class Cleaner : public GameObject {
public:
    Cleaner(); // Конструктор
    void clearFullLines(Field& field); 
    void draw() const override;
    void update() override;
};
