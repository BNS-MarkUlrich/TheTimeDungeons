#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/System/Vector2.hpp>
#include "Room.h"
#include "Collider.h"
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy();
	void start();
	void update();
	void fixedUpdate(sf::Time deltaTime); // Update player's state
	void draw(sf::RenderWindow& window); // Draw the player

	// Other player methods and properties
	Room currentRoom;
};

#endif