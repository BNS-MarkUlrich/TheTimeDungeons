#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
	name = "Enemy";

	shape.setFillColor(sf::Color::Red);
	shape.setRadius(10.0f);
}

void Enemy::start() {
	GameObject::start();

	currentPosition = currentRoom.getCenter();
	shape.setPosition(currentPosition);
	velocity = sf::Vector2f(0, 0);
}

void Enemy::update() {
	GameObject::update();
}

void Enemy::fixedUpdate(sf::Time deltaTime) {
	if (isColliding) {
		isColliding = false;
		return;
	}

	GameObject::fixedUpdate(deltaTime);

	currentPosition = shape.getPosition();
}

void Enemy::draw(sf::RenderWindow& window) {
	GameObject::draw(window);
}

void Enemy::OnCollisionStart(const Collider& other) const {
	std::cout << "TEST Enemy collided with " << other.name << std::endl;
}
