#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct Collider {
	int* id;
	std::string* name;
	sf::Shape* shape;
	sf::Vector2f* velocity;
	bool* isColliding;
	bool* isTrigger;
	std::map<int, bool>* collisionMap;

public:
	Collider* hitCollider;

	void OnCollisionEnter(const Collider& other) const {
		std::cout << *name << " started colliding with " << *other.name << std::endl;
	}

	void OnTriggerEnter(Collider& other) {

	}

	void OnCollisionExit(const Collider& other) const {
		std::cout << *name << " stopped colliding with " << *other.name << std::endl;
	}

	void OnTriggerExit(Collider& other) {

	}
};

#endif