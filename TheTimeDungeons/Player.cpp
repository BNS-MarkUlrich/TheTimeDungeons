#include "Player.h"
#include <iostream>

Player::Player() {
    name = "Player";

    movementSpeed = 2.25f;
    maxMovementSpeed = movementSpeed;
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(10.0f);
}

void Player::start() {
    Collider::start();

	currentPosition = sf::Vector2f(150,150);
    shape.setPosition(currentPosition);
}

void Player::update() {
    Collider::update();
    if (inputParser.isKeyPressed(Action::BoostSpeed)) {
		activateBoost();
	}
}

void Player::fixedUpdate(sf::Time deltaTime) {
    Collider::fixedUpdate(deltaTime);

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
    //Collider::draw(window);
    shape.setPosition(currentPosition);
    window.draw(shape);
}

void Player::move(sf::Vector2f direction, sf::Time deltaTime) {
    float finalMovementSpeed = movementSpeed;

    if (direction.x != 0 && direction.y != 0) {
        finalMovementSpeed = movementSpeed / diagonalMovementDivider;
    }

    sf::Vector2f force = finalMovementSpeed * speedBoostMultiplier * direction;
    force = force * deltaTime.asSeconds();
    //velocity += force;
    colVelocity->x += force.x;
    colVelocity->y += force.y;

    if (abs(colVelocity->x) > finalMovementSpeed * speedBoostMultiplier) {
        colVelocity->x = finalMovementSpeed * speedBoostMultiplier * direction.x;
	}

    if (abs(colVelocity->y) > finalMovementSpeed * speedBoostMultiplier) {
        colVelocity->y = finalMovementSpeed * speedBoostMultiplier * direction.y;
	}
}

void Player::attack() {
    // On Collision with an enemy, deal damage
    isTrigger = true;
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
    speedBoostMultiplier = MathUtils::lerp(speedBoostMultiplier, 0.5f, deltaTime, sf::seconds(boostDuration));
    //std::cout << "Boosted Speed: " << speedBoostMultiplier << std::endl;
}

void Player::resetSpeed() {
	speedBoostMultiplier = 1.0f;
	isBoosted = false;
    isTrigger = false;
	std::cout << "Reset Speed" << std::endl;
}

void Player::OnCollisionEnter(Collider* other) {
	std::cout << "TEST Player collided with: " << other->name << std::endl;
}