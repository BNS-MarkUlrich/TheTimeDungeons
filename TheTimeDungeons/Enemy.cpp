#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
	std::cout << "Enemy created" << std::endl;

	shape.setFillColor(sf::Color::Red);
	shape.setRadius(10.0f);

	collider.name = &name;
	collider.shape = &shape;
	collider.velocity = &velocity;
	collider.hasCollided = &hasCollided;
}

void Enemy::start() {
	std::cout << "Enemy started" << std::endl;

	currentPosition = currentRoom.getCenter();
	shape.setPosition(currentPosition);
	velocity = sf::Vector2f(-1, 0);
}

void Enemy::update() {}

void Enemy::fixedUpdate(sf::Time deltaTime) {
	currentPosition = collider.shape->getPosition();

	if (hasCollided) {
		hasCollided = false;
		return;
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	shape.setPosition(currentPosition);
	window.draw(shape);
}

sf::Vector2f Enemy::getPosition() {
	return currentPosition;
}