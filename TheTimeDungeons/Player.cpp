#include "Player.h"
#include <iostream>

Player::Player() {
    name = "Player";

    movementSpeed = 1.25f;
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(10.0f);
}

void Player::start() {
    GameObject::start();

	currentPosition = sf::Vector2f(0,0);
    shape.setPosition(currentPosition);
}

void Player::update() {
    GameObject::update();
    if (inputParser.isKeyPressed(Action::BoostSpeed)) {
		activateBoost();
	}
}

void Player::fixedUpdate(sf::Time deltaTime) {
    GameObject::fixedUpdate(deltaTime);
    if (isBoosted && speedBoostMultiplier > 1.15f)
    {
        boostSpeed(deltaTime);
        attack();
    }
    else if (isBoosted && speedBoostMultiplier <= 1.15f) {
		resetSpeed();
	}

    moveDirection = inputParser.getMoveDirection();
    move(moveDirection, deltaTime);
}

void Player::draw(sf::RenderWindow& window) 
{
    GameObject::draw(window);
    shape.setPosition(currentPosition);
    window.draw(shape);
}

void Player::move(sf::Vector2f direction, sf::Time deltaTime) {
    if (direction.x == 0 && direction.y == 0) {
        setVelocity(sf::Vector2f(0, 0), deltaTime, 1.0f);
		return;
    }

    float finalMovementSpeed = movementSpeed;

    if (direction.x != 0 && direction.y != 0) {
        finalMovementSpeed = movementSpeed / diagonalMovementDivider;
    }

    velocity = finalMovementSpeed * speedBoostMultiplier * direction;
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
    //std::cout << "Boosted Speed: " << speedBoostMultiplier << std::endl;
}

void Player::resetSpeed() {
	speedBoostMultiplier = 1.0f;
	isBoosted = false;
	std::cout << "Reset Speed" << std::endl;
}