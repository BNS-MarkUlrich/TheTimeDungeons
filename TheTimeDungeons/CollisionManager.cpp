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
            *colliders[i].isColliding = true;
		}
        if (colliders[i].shape->getPosition().y < 0 || colliders[i].shape->getPosition().y > 600) {
            colliders[i].velocity->y *= -1;
            *colliders[i].isColliding = true;
        }
    }

    // Check for collisions
    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            if (isCollision(*colliders[i].shape, *colliders[j].shape)) {
                // Handle collision using a separate function (optional)
                handleCollision(colliders[i], colliders[j]);
            }
            else
            {
                // Handle collision exit
                if (colliders[i].collisionMap->count(*colliders[j].id) > 0) {
					colliders[i].collisionMap->erase(*colliders[j].id);
                    colliders[i].OnCollisionExit(colliders[j]);
                    *colliders[i].isColliding = false;
				}
                // Handle collision exit
                if (colliders[j].collisionMap->count(*colliders[i].id) > 0) {
					colliders[j].collisionMap->erase(*colliders[i].id);
					colliders[j].OnCollisionExit(colliders[i]);
					*colliders[j].isColliding = false;
                }
            }
        }
    }
}

void CollisionManager::handleCollision(const Collider& collider1, const Collider& collider2) {
    // Check if the collision has already been handled
    if (collider1.collisionMap->count(*collider2.id) == 0) { 
        // Add the collision to the map
        collider1.collisionMap->insert(std::pair<int, bool>(*collider2.id, true));
        collider1.OnCollisionEnter(collider2);
        *collider1.isColliding = true;
        *collider1.hitCollider = collider2;

        // Check if the collision has already been handled
        if (collider2.collisionMap->count(*collider1.id) == 0) { 
            // Add the collision to the map
            collider2.collisionMap->insert(std::pair<int, bool>(*collider1.id, true));
			collider2.OnCollisionEnter(collider1);
			*collider2.isColliding = true;
            *collider2.hitCollider = collider1;
        }
        return;
	}

    if (*collider1.isTrigger || *collider2.isTrigger) {
		// Handle trigger logic here
		return;
	}

    //std::cout << "Collision detected between " << *collider1.name << " and " << *collider2.name << std::endl;
	// Handle collision logic here
    *collider1.isColliding = true;
    *collider2.isColliding = true;
}