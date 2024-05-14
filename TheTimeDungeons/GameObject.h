#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>

#include "MathUtils.h"
#include "Room.h"

class GameObject
{
public:
    GameObject();
    GameObject(std::string name);

    sf::Vector2f getPosition();
    Room currentRoom;

    int id;
    std::string name = "GameObject";
    sf::Vector2f currentPosition;
    sf::CircleShape shape;

    // Standard methods
    void start();
    void update();
    void fixedUpdate(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif