#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {
	name = "Enemy";

	shape.setFillColor(sf::Color::Red);
	shape.setRadius(10.0f);
	velocity = sf::Vector2f(2, 0);
}

void Enemy::start() {
	GameObject::start();

	currentPosition = currentRoom.getCenter();
	shape.setPosition(currentPosition);
	velocity = sf::Vector2f(2, 0);
}

void Enemy::update() {
	GameObject::update();
}

void Enemy::fixedUpdate(sf::Time deltaTime) {
	GameObject::fixedUpdate(deltaTime);

	currentPosition = shape.getPosition();
}

void Enemy::draw(sf::RenderWindow& window) {
	GameObject::draw(window);
}

void Enemy::OnCollisionEnter(Collider* other) {
	Collider::Collider::OnCollisionEnter(other);
	//std::cout << name << " collided with " << other->name << std::endl;
}
