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

	void OnCollisionEnter(const Collider& other) const {
		OnCollisionStart(other);
	}

	virtual void OnCollisionStart(const Collider& other) const {
		std::cout << name << " started colliding with " << other.name << std::endl;
	}

	void OnCollisionStay(const Collider& other) const {
		colVelocity->x *= -1 * 0.5;
		colVelocity->y *= -1 * 0.5;
	}

	void OnTriggerEnter(Collider& other) {
		std::cout << name << " entered trigger with " << other.name << std::endl;
	}

	void OnCollisionExit(const Collider& other) const {
		std::cout << name << " stopped colliding with " << other.name << std::endl;
	}

	void OnTriggerExit(Collider& other) {

	}

	// Standard methods
	void start();
	void update();
	void fixedUpdate(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);

	sf::Vector2f velocity;
	bool isColliding = false;
	bool isTrigger = false;
	std::map<int, bool> collisionMap;
	void setVelocity(sf::Vector2f newVelocity, sf::Time deltaTime, float duration);
	void physicsUpdate(sf::Time deltaTime);
};

#endif