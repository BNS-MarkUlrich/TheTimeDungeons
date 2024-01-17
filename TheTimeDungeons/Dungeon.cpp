#include "Dungeon.h"

Dungeon::Dungeon(int width, int height) : width(width), height(height) {
    rooms.resize(height, std::vector<Room>(width));
    setCurrentRoom(0, height - 1); // Starting room at bottom-left
}

void Dungeon::generateDungeon() {
    // Dungeon generation logic, including room size and exit points
}

Room& Dungeon::getCurrentRoom() {
    return rooms[currentRoomPosition.y][currentRoomPosition.x];
}

void Dungeon::setCurrentRoom(int x, int y) {
    currentRoomPosition = sf::Vector2i(x, y);
}