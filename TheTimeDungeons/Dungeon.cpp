#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(int width, int height) : width(width), height(height) {
    rooms.resize(height, std::vector<Room>(width));

    sf::Vector2f startingRoomSize = sf::Vector2f(800, 400);
    sf::Vector2f startingRoomPosition = sf::Vector2f(50, height - 1);

    Room startingRoom = Room(startingRoomSize, startingRoomPosition);
    rooms[0][0] = startingRoom;

    setCurrentRoom(startingRoom, startingRoomPosition); 
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
    currentRoomPosition = sf::Vector2f();
}