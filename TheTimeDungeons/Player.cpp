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
    if (inputParser.isKeyPressed(Action::BoostSpeed)) {
		activateBoost();
	}
}

void Player::fixedUpdate(sf::Time deltaTime) {
    if (isBoosted && speedBoostMultiplier > 1.15f)
    {
        boostSpeed(deltaTime);
        attack();
        //return; // Unlock together with move call in boostSpeed for locked direction while boosting
    }
    else if (isBoosted && speedBoostMultiplier <= 1.15f) {
		resetSpeed();
	}

    moveDirection = inputParser.getMoveDirection();
    move(moveDirection);
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
        finalMovementSpeed = movementSpeed / diagonalMovementDivider;
    }

    velocity = finalMovementSpeed * speedBoostMultiplier * direction;
	shape.move(velocity);
    currentPosition = shape.getPosition();
}

void Player::attack() {
    // On Collision with an enemy, deal damage
    // Make player invulnerable while attacking
    //if (shape.getGlobalBounds().intersects(obstacle.getGlobalBounds())) {
    //    // Handle collision
    //    std::cout << "Collision detected!" << std::endl;
    //}
}

void Player::activateBoost() {
    if (isBoosted) {
        return;
    }

    if (moveDirection.x == 0 && moveDirection.y == 0) {
		return;
	}

    isBoosted = true;
	speedBoostMultiplier = maxSpeedBoostMultiplier;
    std::cout << "Activated Boost" << std::endl;
}

void Player::boostSpeed(sf::Time deltaTime) {
    speedBoostMultiplier = MathUtils::lerp(speedBoostMultiplier, 1.0f, deltaTime, sf::seconds(boostDuration));
    //move(moveDirection); // Unlock together with return call in fixedUpdate for locked direction while boosting
    std::cout << "Boosted Speed: " << speedBoostMultiplier << std::endl;
}

void Player::resetSpeed() {
	speedBoostMultiplier = 1.0f;
	isBoosted = false;
	std::cout << "Reset Speed" << std::endl;
}