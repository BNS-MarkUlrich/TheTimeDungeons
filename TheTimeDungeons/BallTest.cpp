#include "BallTest.h"

BallTest::BallTest() 
{
    shape.setFillColor(sf::Color::Red); // Set ball color
}

BallTest::~BallTest()
{
}

void BallTest::setRadius(float radius) 
{
    shape.setRadius(radius);
    shape.setOrigin(radius, radius); // Set the origin to the center of the ball
}

sf::CircleShape BallTest::getShape() const 
{
    return shape;
}