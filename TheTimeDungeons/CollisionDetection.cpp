#include "CollisionDetection.h"
#include <iostream>

bool isCollision(const sf::Shape& shape1, const sf::Shape& shape2) {
	// Implement shape-shape collision detection
	// You can find many algorithms online
	if (dynamic_cast<const sf::RectangleShape*>(&shape1) && dynamic_cast<const sf::RectangleShape*>(&shape2)) {
		return isCollision(dynamic_cast<const sf::RectangleShape&>(shape1), dynamic_cast<const sf::RectangleShape&>(shape2));
	}
	else if (dynamic_cast<const sf::CircleShape*>(&shape1) && dynamic_cast<const sf::CircleShape*>(&shape2)) {
		return isCollision(dynamic_cast<const sf::CircleShape&>(shape1), dynamic_cast<const sf::CircleShape&>(shape2));
	}
	else if (dynamic_cast<const sf::CircleShape*>(&shape1) && dynamic_cast<const sf::RectangleShape*>(&shape2)) {
		return isCollision(dynamic_cast<const sf::CircleShape&>(shape1), dynamic_cast<const sf::RectangleShape&>(shape2));
	}
	else if (dynamic_cast<const sf::RectangleShape*>(&shape1) && dynamic_cast<const sf::CircleShape*>(&shape2)) {
		return isCollision(dynamic_cast<const sf::CircleShape&>(shape2), dynamic_cast<const sf::RectangleShape&>(shape1));
	}

	return false;
}

bool isCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
	return rect1.getGlobalBounds().intersects(rect2.getGlobalBounds());
}

bool isCollision(const sf::CircleShape& circle, const sf::RectangleShape& rect) {
	// Implement circle-rectangle collision detection
	// You can find many algorithms online
	return false;
}

bool isCollision(const sf::CircleShape& circle1, const sf::CircleShape& circle2) {
	float radiusSum = circle1.getRadius() + circle2.getRadius();
	sf::Vector2f centerDist = circle1.getPosition() - circle2.getPosition();
	return (centerDist.x * centerDist.x + centerDist.y * centerDist.y) < radiusSum * radiusSum;
}
