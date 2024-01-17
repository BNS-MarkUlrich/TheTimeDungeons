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
    void setCurrentRoom(int x, int y);

private:
    std::vector<std::vector<Room>> rooms;
    int width, height;
    sf::Vector2i currentRoomPosition;
};

#endif
