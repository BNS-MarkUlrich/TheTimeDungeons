#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/System/Vector2.hpp>
#include "Room.h"
#include "Collider.h"

class Enemy {
public:
	Enemy();
	Enemy(Room startingRoom);

	void start();
	void update();
	void fixedUpdate(sf::Time deltaTime); // Update player's state
	void draw(sf::RenderWindow& window); // Draw the player

	// Other player methods and properties
	sf::Vector2f getPosition();
	Room currentRoom;
	Collider collider;

private:
	sf::Vector2f currentPosition;
	sf::CircleShape shape; // SFML shape for the player
};

#endif