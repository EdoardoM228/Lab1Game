#include "game.h"
#include "figure.h"
#include "clear.h"
#include "field.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void handleInput(RenderWindow& window, int& dx, bool& rotate) {
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

void updateGameState(RenderWindow& window, int& dx, bool& rotate, float& timer, float delay, int& colorNum) {

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
                field[b[i].y][b[i].x] = colorNum;  
            generateNewFigure(); 
            colorNum = 1 + rand() % 7;  
        }

        timer = 0;  
    }

    dx = 0;
}
