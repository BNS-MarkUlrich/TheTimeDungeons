#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "Collider.h"
#include <vector>

class CollisionManager {
public:
	void addCollider(Collider& collider);
	void fixedUpdate(sf::Time deltaTime);

private:
	std::vector<Collider> colliders;

	void handleCollision(const Collider& collider1, const Collider& collider2);
};

#endif