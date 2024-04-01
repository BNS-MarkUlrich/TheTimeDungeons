#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>

#include "MathUtils.h"
#include "Collider.h"

#pragma once

class GameObject
{
public:
    GameObject();
    GameObject(std::string name);

    sf::Vector2f getPosition();
    Collider collider;

protected:
    int id;
    std::string name = "GameObject";
    sf::Vector2f currentPosition;
    sf::CircleShape shape;

    // Standard methods
    void start();
    void update();
    void fixedUpdate(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);

    // Physics
    sf::Vector2f velocity;
    bool isColliding = false;
    bool isTrigger = false;
    std::map<int, bool> collisionMap;
    std::string hitColliderName = "None";
    void setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration);
    void physicsUpdate(sf::Time deltaTime);
};

#endif