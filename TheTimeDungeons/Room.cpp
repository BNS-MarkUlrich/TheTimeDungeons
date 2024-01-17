#include "Room.h"

Room::Room(sf::Vector2f size)
{
    this->size = size;
}

void Room::draw(sf::RenderWindow& window) {
    // Drawing logic for the room using SFML shapes
    // draw walls as white lines
    // draw floor as black rectangle

    // Draw walls as white lines
    sf::RectangleShape topWall(sf::Vector2f(size.x, 1));
    topWall.setFillColor(sf::Color::White);
    topWall.setPosition(0, 0);
    window.draw(topWall);

    sf::RectangleShape bottomWall(sf::Vector2f(size.x, 1));
    bottomWall.setFillColor(sf::Color::White);
    bottomWall.setPosition(0, size.y - 1);
    window.draw(bottomWall);

    sf::RectangleShape leftWall(sf::Vector2f(1, size.y));
    leftWall.setFillColor(sf::Color::White);
    leftWall.setPosition(0, 0);
    window.draw(leftWall);

    sf::RectangleShape rightWall(sf::Vector2f(1, size.y));
    rightWall.setFillColor(sf::Color::White);
    rightWall.setPosition(size.x - 1, 0);
    window.draw(rightWall);
}