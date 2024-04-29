#include "CollisionManager.h"
#include "CollisionDetection.h"
#include <iostream>
#include "Game.h"

void CollisionManager::addCollider(Collider& collider) {
    colliders.push_back(collider);
}

void CollisionManager::fixedUpdate(sf::Time deltaTime) {
    // Update collider positions based on velocity
    for (int i = 0; i < colliders.size(); i++) {
        colliders[i].colliderShape->move(*colliders[i].colVelocity);
       
        // Below is an example of how to handle collisions with the window boundaries
        if (colliders[i].colliderShape->getPosition().x < 0 || colliders[i].colliderShape->getPosition().x > 800) {
            colliders[i].isColliding = true;
            colliders[i].colVelocity->x = -colliders[i].colVelocity->x;
		}
        if (colliders[i].colliderShape->getPosition().y < 0 || colliders[i].colliderShape->getPosition().y > 600) {
            colliders[i].isColliding = true;
            colliders[i].colVelocity->y = -colliders[i].colVelocity->y;
        }
    }

    // Check for collisions
    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            if (isCollision(*colliders[i].colliderShape, *colliders[j].colliderShape)) {
                // Handle collision using a separate function (optional)
                handleCollision(colliders[i], colliders[j]);
            }
            else
            {
                // Handle collision exit
                if (colliders[i].collisionMap.count(colliders[j].id) > 0) {
					colliders[i].collisionMap.erase(colliders[j].id);
                    colliders[i].OnCollisionExit(colliders[j]);
				}
                // Handle collision exit
                if (colliders[j].collisionMap.count(colliders[i].id) > 0) {
					colliders[j].collisionMap.erase(colliders[i].id);
					colliders[j].OnCollisionExit(colliders[i]);
                }
            }
        }
    }
}

void CollisionManager::handleCollision(Collider& collider1, Collider& collider2) const {
    // Check if the collision has already been handled
    Player* player = static_cast<Player*>(&collider1);
    Enemy* enemy = static_cast<Enemy*>(&collider2);

    if (player->collisionMap.count(collider2.id) == 0) {
        // Add the collision to the map
        player->collisionMap.insert(std::pair<int, bool>(collider2.id, true));
        player->OnCollisionEnter(&collider2);

        // Check if the collision has already been handled
        if (enemy->collisionMap.count(player->id) == 0) {
            // Add the collision to the map
            enemy->collisionMap.insert(std::pair<int, bool>(player->id, true));
            enemy->OnCollisionEnter(player);
        }
        return;
    }

    if (player->isTrigger || enemy->isTrigger) {
		// Handle trigger logic here
        std::cout << "Triggered" << std::endl;
		return;
	}

    player->isColliding = true;
    player->OnCollisionStay(collider2);
    enemy->isColliding = true;
    enemy->OnCollisionStay(collider1);
}