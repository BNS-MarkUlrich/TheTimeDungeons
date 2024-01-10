#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::updatePhysicsBody(float deltaTime)
{
    // Update velocity based on acceleration
    velocity += acceleration * deltaTime;

    // Update position based on velocity
    object.setPosition(object.getPosition() + velocity * deltaTime);
}

void PhysicsObject::setVelocity(sf::Vector2f newVelocity) 
{
	velocity = newVelocity;
}

void PhysicsObject::setAcceleration(sf::Vector2f newAcceleration) 
{
	acceleration = newAcceleration;
}

void PhysicsObject::setPosition(sf::Vector2f newPosition) 
{
	object.setPosition(newPosition);
}

sf::Vector2f PhysicsObject::getPosition() const 
{
	return object.getPosition();
}
