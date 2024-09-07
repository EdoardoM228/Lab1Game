#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Tetris.h"

using namespace sf;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    RenderWindow window(VideoMode(320, 480), "The Game!");

    Texture t1, t2, t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");

    Sprite s(t1), background(t2), frame(t3);

    int dx = 0;
    bool rotate = false;
    int colorNum = 1;
    float timer = 0, delay = 0.3f;

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        handleInput(window, dx, rotate);

        if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05f;

        updateGameState(window, dx, rotate, timer, delay, colorNum);

        dx = 0; rotate = false; delay = 0.3f;

        window.clear(Color::White);
        window.draw(background);

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0) continue;
                s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                s.setPosition(j * 18, i * 18);
                s.move(28, 31); // offset
                window.draw(s);
            }

        for (int i = 0; i < 4; i++)
        {
            s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            s.setPosition(a[i].x * 18, a[i].y * 18);
            s.move(28, 31); // offset
            window.draw(s);
        }

        window.draw(frame);
        window.display();
    }

    return 0;
}
