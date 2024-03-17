#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

struct Collider {
	std::string name;
	sf::Shape* shape; // Change to this if you want to use any shape
	//sf::Vector2f velocity;
};

#endif