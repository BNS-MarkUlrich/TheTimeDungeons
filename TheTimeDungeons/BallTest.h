#pragma once

#include "PhysicsObject.h"

class BallTest : public PhysicsObject
{
public:
	BallTest();
	~BallTest();

	void setRadius(float radius);
	sf::CircleShape getShape() const;

private:
	sf::CircleShape shape;
};

