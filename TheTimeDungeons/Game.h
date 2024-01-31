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
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    sf::View view;

    Player player;
    Dungeon dungeon;
};
