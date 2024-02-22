#include "Player.h"
#include <iostream>

Player::Player() {
    // Set current position to the center of the current room in the Dungeon
    movementSpeed = 1.25f;
}

void Player::start() {
    std::cout << "Player started" << std::endl;

	currentPosition = currentRoom.getCenter();
}

void Player::update() {
	// Update is called every rendered frame.
}

void Player::fixedUpdate(sf::Time deltaTime) {
    // Fixed update is called at a fixed time step, meaning it called independantly from the current framerate.
    // Update logic for the player, including movement and collision detection

    sf::Vector2f direction = inputParser.getMoveDirection();
    move(direction);
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

    float finalMovementSpeed = movementSpeed;

    if (direction.x != 0 && direction.y != 0) {
        finalMovementSpeed = movementSpeed / 1.414f;
    }

    sf::Vector2f velocity = direction * finalMovementSpeed;
	shape.move(velocity);
    currentPosition = shape.getPosition();
}