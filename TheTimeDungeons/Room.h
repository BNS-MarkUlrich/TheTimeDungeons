#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <vector>

class Room {
	// Additional Room properties and methods

	// Know the size of the room and exit points
	// Implement functionality for checking if a point is inside the room
	// Implement grid (for AI pathfinding later)

public:
	Room(sf::Vector2f size);
	void draw(sf::RenderWindow& window);

private:
	sf::Vector2f size;
};

#endif
