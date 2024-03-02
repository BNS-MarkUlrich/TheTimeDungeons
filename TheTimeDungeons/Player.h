#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "GameObject.h"

#include "MathUtils.h"
#include "Room.h"
#include "InputParser.h"

class Player : public GameObject {
public:
    Player();
    void start();
    void update();
    void fixedUpdate(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const override { return shape.getGlobalBounds(); }

    // Other player methods and properties
    sf::Vector2f getPosition();
    Room currentRoom;
    
private:
    InputParser inputParser;

    sf::Vector2f currentPosition;
    sf::CircleShape shape; // SFML shape for the player
    sf::Vector2f moveDirection;
    sf::Vector2f velocity;
    float movementSpeed = 1.0f;
    float diagonalMovementDivider = 1.414f; // Used to divide the movement speed when moving diagonally
    float speedBoostMultiplier = 1.0f;
    float maxSpeedBoostMultiplier = 12.0f;
    float boostDuration = 0.35f;
    bool isBoosted = false;

    void move(sf::Vector2f direction);
    void attack();
    void activateBoost();
    void boostSpeed(sf::Time deltaTime);
    void resetSpeed();
};

#endif
