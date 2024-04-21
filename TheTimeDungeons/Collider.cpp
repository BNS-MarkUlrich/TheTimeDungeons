#include "Collider.h"

Collider::Collider() : GameObject() {
	colliderShape = &shape;
	colVelocity = &velocity;
}

void Collider::start() {
	GameObject::start();
}

void Collider::update() {
	GameObject::update();
}

void Collider::fixedUpdate(sf::Time deltaTime) {
	GameObject::fixedUpdate(deltaTime);
	physicsUpdate(deltaTime);
}

void Collider::draw(sf::RenderWindow& window) {
	GameObject::draw(window);
}

void Collider::physicsUpdate(sf::Time deltaTime) {
	if (isColliding && !isTrigger) {
		isColliding = false;
		return;
	}

	if (abs(velocity.x) > 0) {
		velocity.x = MathUtils::lerp(velocity.x, 0, deltaTime, sf::seconds(0.5f));
	}

	if (abs(velocity.y) > 0) {
		velocity.y = MathUtils::lerp(velocity.y, 0, deltaTime, sf::seconds(0.5f));
	}

	//currentPosition += velocity * deltaTime.asSeconds();
	currentPosition = shape.getPosition();
}

void Collider::setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration) {
	velocity = MathUtils::lerp(velocity, newVelocity, deltaTime, sf::seconds(duration));
}