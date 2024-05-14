#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Collider : public GameObject {
public:
	Collider();
	sf::Shape* colliderShape;
	sf::Vector2f* colVelocity;

	void OnCollisionEnter(Collider* other) {
		isColliding = true;
	}

	void OnCollisionStay(const Collider& other) const {
		colVelocity->x *= -1 * 0.5;
		colVelocity->y *= -1 * 0.5;
	}

	void OnTriggerEnter(Collider& other) {
		std::cout << name << " entered trigger with " << other.name << std::endl;
	}

	void OnCollisionExit(Collider& other) {
		std::cout << name << " stopped colliding with " << other.name << std::endl;
		isColliding = false;
	}

	void OnTriggerExit(Collider& other) {

	}

	// Standard methods
	virtual void start() {
		GameObject::start();
	}

	virtual void update() {
		GameObject::update();
	}

	virtual void fixedUpdate(sf::Time deltaTime) {
		GameObject::fixedUpdate(deltaTime);
		physicsUpdate(deltaTime);
	}

	virtual void draw(sf::RenderWindow& window) {
		GameObject::draw(window);
	}

	sf::Vector2f velocity;
	bool isColliding;
	bool isTrigger;
	std::map<int, bool> collisionMap;

	virtual void setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration) {
		velocity = MathUtils::lerp(velocity, newVelocity, deltaTime, sf::seconds(duration));
	}

	void physicsUpdate(sf::Time deltaTime) {
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

		currentPosition = shape.getPosition();
	}
};

#endif