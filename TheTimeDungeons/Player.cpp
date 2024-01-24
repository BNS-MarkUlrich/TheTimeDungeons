#include "Player.h"

Player::Player() {
    // Initialize player properties, including SFML shape
}

void Player::update(sf::Time deltaTime) {
    // Update logic for the player, including movement and collision detection
}

void Player::draw(sf::RenderWindow& window) 
{
    currentPosition = sf::Vector2f(50, 50); // Set the position of the player
    shape.setPosition(currentPosition); // Set the position of the player shape
    shape.setFillColor(sf::Color::Green); // Set the color of the player shape
    shape.setRadius(10.0f); // Set the radius of the player shape
    window.draw(shape); // Draw the player shape
}
