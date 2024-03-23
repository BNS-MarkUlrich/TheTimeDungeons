#include "CollisionManager.h"
#include "CollisionDetection.h"
#include <iostream>

void CollisionManager::addCollider(Collider& collider) {
    colliders.push_back(collider);
}

void CollisionManager::fixedUpdate(sf::Time deltaTime) {
    // Update collider positions based on velocity
    for (int i = 0; i < colliders.size(); i++) {
        colliders[i].shape->move(*colliders[i].velocity);
       
        // Below is an example of how to handle collisions with the window boundaries
        if (colliders[i].shape->getPosition().x < 0 || colliders[i].shape->getPosition().x > 800) {
			colliders[i].velocity->x *= -1;
            *colliders[i].hasCollided = true;
		}
        if (colliders[i].shape->getPosition().y < 0 || colliders[i].shape->getPosition().y > 600) {
            colliders[i].velocity->y *= -1;
            *colliders[i].hasCollided = true;
        }
    }

    // Check for collisions
    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            if (isCollision(*colliders[i].shape, *colliders[j].shape)) {
                // Handle collision using a separate function (optional)
                handleCollision(colliders[i], colliders[j]);
            }
        }
    }
}

void CollisionManager::handleCollision(const Collider& collider1, const Collider& collider2) {
    std::cout << "Collision detected between " << *collider1.name << " and " << *collider2.name << std::endl;
	// Handle collision logic here
    *collider1.hasCollided = true;
    *collider2.hasCollided = true;
    collider1.velocity->x *= -1;
    collider1.velocity->y *= -1;
    collider2.velocity->x *= -1;
    collider2.velocity->y *= -1;
}