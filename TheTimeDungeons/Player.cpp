#include "Player.h"
#include <iostream>

Player::Player() {
    currentPosition = sf::Vector2f(50, 50);
    movementSpeed = 0.25f;
}

void Player::update(sf::Time deltaTime) {
    // Update logic for the player, including movement and collision detection

    sf::Vector2f direction = inputParser.getMoveDirection();
    move(direction * movementSpeed);
}

void Player::draw(sf::RenderWindow& window) 
{
    shape.setPosition(currentPosition);
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(10.0f);
    window.draw(shape);
}

sf::Vector2f Player::getPosition() {
    return currentPosition;
}

void Player::move(sf::Vector2f direction) {
    if (direction.x == 0 && direction.y == 0) {
		return;
    }

	shape.move(direction);
    currentPosition = shape.getPosition();
}