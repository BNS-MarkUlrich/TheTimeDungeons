#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(int width, int height) : width(width), height(height) {
    rooms.resize(height, std::vector<Room>(width));

    sf::Vector2f startingRoomSize = sf::Vector2f(100, 100);
    sf::Vector2f startingRoomPosition = sf::Vector2f(50, height - 1);

    Room startingRoom = Room(startingRoomSize);
    rooms[0][0] = startingRoom;

    setCurrentRoom(startingRoom, startingRoomPosition); // Starting room at bottom-left

    //std::cout << "Dungeon generated with " << width << "x" << height << " rooms" << std::endl;
}

void Dungeon::generateDungeon() {
    // Dungeon generation logic, including room size and exit points
}

Room Dungeon::getCurrentRoom() {
    return currentRoom;
}

void Dungeon::setCurrentRoom(Room room, sf::Vector2f roomPosition) 
{
    currentRoom = room;
    currentRoomPosition = sf::Vector2i();
}