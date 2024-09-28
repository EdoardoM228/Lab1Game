#include <SFML/Graphics.hpp>
#include "figure.h"
#include "game.h"
#include "clear.h"
#include "field.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(320, 480), "Tetris");

    Texture t;
    t.loadFromFile("images/tiles.png");
    Sprite s(t);

    int dx = 0;  
    bool rotate = false;
    float timer = 0, delay = 0.3;
    Clock clock;
    int colorNum = 1;

    generateNewFigure(); 

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        handleInput(window, dx, rotate); 
        updateGameState(window, dx, rotate, timer, delay, colorNum);  

        clearFullLines();  

        window.clear(Color::White);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 0) continue;
                s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                s.setPosition(j * 18, i * 18);
                window.draw(s);
            }

        for (int i = 0; i < 4; i++) {
            s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            s.setPosition(a[i].x * 18, a[i].y * 18);
            window.draw(s);
        }

        window.display();
    }

    return 0;
}