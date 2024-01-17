#include "Player.h"

Player::Player() {
    // Initialize player properties, including SFML shape
}

void Player::update(sf::Time deltaTime) {
    // Update logic for the player, including movement and collision detection
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape); // Draw the player shape
}
