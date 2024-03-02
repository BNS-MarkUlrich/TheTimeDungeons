#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

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

    float lerp(float a, float b, float f) {
		return a + f * (b - a);
	}
    
private:
    InputParser inputParser;

    sf::Vector2f currentPosition;
    sf::CircleShape shape; // SFML shape for the player
    float movementSpeed = 1.0f; // Speed of the player

    void move(sf::Vector2f direction);
};

#endif
