#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Dungeon.h"


class Game 
{
public:
    Game();
    void run();

private:
    void start();
    void processEvents();
    void update();
    void fixedUpdate(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    sf::View view;
    sf::Time deltaTime;

    Player player;
    Dungeon dungeon;
};
