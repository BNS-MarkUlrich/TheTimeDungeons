#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <vector>

class Dungeon {
	// Implement functionality for moving/teleporting player between rooms via connected entry and exit points
	// Implement a starting room
	// Implement a current room (the room the player is in)

	// Randomly generate a dungeon

public:
    Dungeon(int width, int height);
    void generateDungeon();
    Room& getCurrentRoom();
    void setCurrentRoom(Room room, sf::Vector2f roomPosition);

private:
    std::vector<std::vector<Room>> rooms;
    int width, height;
    Room currentRoom = Room(sf::Vector2f(10, 10));
    sf::Vector2i currentRoomPosition;
};

#endif
