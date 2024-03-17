#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

struct Collider {
	std::string name;
	sf::Shape* shape;
	sf::Vector2f velocity;
};

#endif