#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
}

GameObject::GameObject(std::string name) {
	this->name = name;
}

void GameObject::start() {
	id = rand() % 1000;
	std::cout << name << " started with ID: " << id << std::endl;
}

void GameObject::update() {}

void GameObject::fixedUpdate(sf::Time deltaTime) {
	//physicsUpdate(deltaTime);
}

//void GameObject::physicsUpdate(sf::Time deltaTime) {
//	if (isColliding && !isTrigger) {
//		isColliding = false;
//		return;
//	}
//
//	/*if (abs(velocity.x) > 0 || abs(velocity.y) > 0) {
//		setVelocity(sf::Vector2f(0, 0), deltaTime, 0.5f);
//	}*/
//
//	if (abs(velocity.x) > 0) {
//		velocity.x = MathUtils::lerp(velocity.x, 0, deltaTime, sf::seconds(0.5f));
//	}
//
//	if (abs(velocity.y) > 0) {
//		velocity.y = MathUtils::lerp(velocity.y, 0, deltaTime, sf::seconds(0.5f));
//	}
//
//	//currentPosition += velocity * deltaTime.asSeconds();
//	currentPosition = shape.getPosition();
//}

void GameObject::draw(sf::RenderWindow& window) {
	shape.setPosition(currentPosition);
	window.draw(shape);
}

sf::Vector2f GameObject::getPosition() {
	return currentPosition;
}

//void GameObject::setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration) {
//	velocity = MathUtils::lerp(velocity, newVelocity, deltaTime, sf::seconds(duration));
//}