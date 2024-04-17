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
		//std::cout << name << " started colliding with " << other.name << std::endl;
	}

	void OnTriggerEnter(Collider& other) {

	}

	void OnCollisionExit(const Collider& other) const {
		std::cout << name << " stopped colliding with " << other.name << std::endl;
	}

	void OnTriggerExit(Collider& other) {

	}
};

#endif