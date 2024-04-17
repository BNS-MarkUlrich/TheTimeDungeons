#include "Collider.h"

Collider::Collider() : GameObject() {
	colliderShape = &shape;
	colVelocity = &velocity;
}