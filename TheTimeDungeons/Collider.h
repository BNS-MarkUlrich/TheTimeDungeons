#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct Collider {
	std::string* name;
	sf::Shape* shape;
	sf::Vector2f* velocity;
	bool* isColliding;
	bool* isTrigger;
	std::map<std::string, bool>* collisionMap;

public:
	void OnCollisionEnter(const Collider& other) const {
		std::cout << *name << " started colliding with " << *other.name << std::endl;
		sf::Vector2f newVelocity = *velocity;
		*other.velocity = newVelocity;
	}

	void OnTriggerEnter(Collider& other) {
		
	}
};

#endif