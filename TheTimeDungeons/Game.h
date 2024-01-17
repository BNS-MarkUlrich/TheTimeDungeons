#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game 
{
public:
    Game() : window(sf::VideoMode(800, 600), "The Time Dungeons") {}
    void run();

    Player player;

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
};
