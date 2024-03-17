#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <SFML/Graphics.hpp>

bool isCollision(const sf::Shape& shape1, const sf::Shape& shape2);
bool isCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2);
bool isCollision(const sf::CircleShape& circle, const sf::RectangleShape& rect);
bool isCollision(const sf::CircleShape& circle1, const sf::CircleShape& circle2);

#endif
