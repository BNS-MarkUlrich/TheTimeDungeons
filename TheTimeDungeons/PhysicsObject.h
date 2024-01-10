#pragma once
#include <SFML/Graphics.hpp>

class PhysicsObject 
{
public:
    PhysicsObject();
    ~PhysicsObject();

    void updatePhysicsBody(float deltaTime);
    void setVelocity(sf::Vector2f newVelocity);
    void setAcceleration(sf::Vector2f newAcceleration);
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition() const;

private:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::CircleShape object;
};
