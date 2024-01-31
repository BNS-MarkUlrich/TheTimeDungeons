#include "Room.h"
#include <iostream>

Room::Room() : size(sf::Vector2f(100.0f, 100.0f)) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    generateExitPoints(1 + rand() % 3); // Generate 1 to 3 exit points
    std::cout << "Room generated with " << exitPoints.size() << " exit points" << std::endl;
}

Room::Room(sf::Vector2f size) : size(size) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    generateExitPoints(1 + rand() % 3); // Generate 1 to 3 exit points
}

void Room::draw(sf::RenderWindow& window) {
    // Drawing logic for the room using SFML shapes
    // Implement the drawing logic here
    // Example: Draw a rectangle representing the room
    sf::RectangleShape roomShape(size);
    roomShape.setFillColor(sf::Color::White);
    roomShape.setPosition(sf::Vector2f(0, 0));
    window.draw(roomShape);
}

void Room::generateExitPoints(unsigned int count) {
    // Clear any existing exit points
    exitPoints.clear();

    for (unsigned int i = 0; i < count; ++i) {
        sf::Vector2f point;
        int wall = rand() % 4; // Choose a random wall (0: top, 1: right, 2: bottom, 3: left)
        switch (wall) {
        case 0: // Top wall
            point.x = static_cast<float>(rand() % static_cast<int>(size.x));
            point.y = 0;
            break;
        case 1: // Right wall
            point.x = size.x;
            point.y = static_cast<float>(rand() % static_cast<int>(size.y));
            break;
        case 2: // Bottom wall
            point.x = static_cast<float>(rand() % static_cast<int>(size.x));
            point.y = size.y;
            break;
        case 3: // Left wall
            point.x = 0;
            point.y = static_cast<float>(rand() % static_cast<int>(size.y));
            break;
        }
        exitPoints.push_back(point);
    }
}

const std::vector<sf::Vector2f>& Room::getExitPoints() const {
    return exitPoints;
}
