#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Dungeon.h"
#include "Enemy.h"
#include "CollisionManager.h"


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
    Enemy enemy;
    Dungeon dungeon;

    std::vector<Collider> colliders;
    CollisionManager collisionManager;
};
