#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include <SFML/Graphics.hpp>

class Player {
    // include methods for moving the player using the WASD keys
    // include methods for checking collisions

public:
    Player();
    void update(sf::Time deltaTime); // Update player's state
    void draw(sf::RenderWindow& window); // Draw the player

    // Other player methods and properties
    
private:
    sf::Vector2f currentPosition;
    sf::CircleShape shape; // SFML shape for the player
};

#endif
