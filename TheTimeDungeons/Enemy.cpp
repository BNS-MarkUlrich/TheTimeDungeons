#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
	std::cout << "Enemy created" << std::endl;

	shape.setFillColor(sf::Color::White);
	shape.setRadius(10.0f);

	collider.name = "Enemy Collider";
	collider.shape = &shape;
}

Enemy::Enemy(Room startingRoom) {
	std::cout << "Enemy created" << std::endl;

	shape.setFillColor(sf::Color::White);
	shape.setRadius(10.0f);

	collider.name = "Enemy Collider";
	collider.shape = &shape;

	currentRoom = startingRoom;
}

void Enemy::start() {
	std::cout << "Enemy started" << std::endl;

	currentPosition = currentRoom.getCenter();
}

void Enemy::update() {}

void Enemy::fixedUpdate(sf::Time deltaTime) {}

void Enemy::draw(sf::RenderWindow& window)
{
	shape.setPosition(currentPosition);
	window.draw(shape);
}

sf::Vector2f Enemy::getPosition() {
	return currentPosition;
}