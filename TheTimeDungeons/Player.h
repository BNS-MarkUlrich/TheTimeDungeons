#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "MathUtils.h"
#include "Room.h"
#include "InputParser.h"

class Player {
    // include methods for moving the player using the WASD keys
    // include methods for checking collisions

public:
    Player();
    void start(); // Start the player
    void update(); // Update player's state
    void fixedUpdate(sf::Time deltaTime); // Update player's state
    void draw(sf::RenderWindow& window); // Draw the player

    // Other player methods and properties
    sf::Vector2f getPosition();
    Room currentRoom;
    
private:
    InputParser inputParser;

    sf::Vector2f currentPosition;
    sf::CircleShape shape; // SFML shape for the player
    sf::Vector2f moveDirection;
    sf::Vector2f velocity;
    float movementSpeed = 1.0f; // Speed of the player
    float diagonalMovementDivider = 1.414f; // Used to divide the movement speed when moving diagonally
    float speedBoostMultiplier = 1.0f; // Used to multiply the movement speed when the player is boosted
    float maxSpeedBoostMultiplier = 12.0f; // Maximum speed boost multiplier
    float boostDuration = 0.35f; // Duration of the speed boost
    bool isBoosted = false; // Whether the player is boosted or not

    void move(sf::Vector2f direction);
    void attack();
    void activateBoost();
    void boostSpeed(sf::Time deltaTime);
    void resetSpeed();
};

#endif
