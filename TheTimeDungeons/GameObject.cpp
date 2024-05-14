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

void GameObject::fixedUpdate(sf::Time deltaTime) {}

void GameObject::draw(sf::RenderWindow& window) {
	shape.setPosition(currentPosition);
	window.draw(shape);
}

sf::Vector2f GameObject::getPosition() {
	return currentPosition;
}