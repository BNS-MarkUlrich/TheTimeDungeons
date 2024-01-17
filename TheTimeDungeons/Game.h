#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Dungeon.h"

class Game 
{
public:
    Game() : window(sf::VideoMode(800, 600), "The Time Dungeons") {}
    void run();

    Player player;
    Dungeon dungeon = Dungeon(50, 50);

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
};
