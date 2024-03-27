#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	collider.name = &name;
	collider.shape = &shape;
	collider.velocity = &velocity;
	collider.isColliding = &isColliding;
	collider.isTrigger = &isTrigger;
	collider.collisionMap = &collisionMap;
}

GameObject::GameObject(std::string name) {
	this->name = name;
	collider.name = &this->name;
	collider.shape = &shape;
	collider.velocity = &velocity;
	collider.isColliding = &isColliding;
	collider.isTrigger = &isTrigger;
	collider.collisionMap = &collisionMap;
}

void GameObject::start() {
	std::cout << name << " started" << std::endl;
}

void GameObject::update() {}

void GameObject::fixedUpdate(sf::Time deltaTime) {
	physicsUpdate(deltaTime);
}

void GameObject::physicsUpdate(sf::Time deltaTime) {
	if (isColliding) {
		isColliding = false;
		return;
	}

	if (velocity.x > 0 || velocity.y > 0) {
		setVelocity(sf::Vector2f(0, 0), deltaTime, 1.0f);
	}

	currentPosition = collider.shape->getPosition();
}

void GameObject::draw(sf::RenderWindow& window) {
	shape.setPosition(currentPosition);
	window.draw(shape);
}

sf::Vector2f GameObject::getPosition() {
	return currentPosition;
}

void GameObject::setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration) {
	velocity = MathUtils::lerp(velocity, newVelocity, deltaTime, sf::seconds(duration));
}