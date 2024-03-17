#include "CollisionManager.h"
#include "CollisionDetection.h"
#include <iostream>

void CollisionManager::addCollider(Collider& collider) {
    colliders.push_back(collider);
}

void CollisionManager::fixedUpdate(sf::Time deltaTime) {
    // Update collider positions based on velocity
    /*for (auto& collider : colliders) {
        collider.shape->move(collider.velocity);
    }*/

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
    std::cout << "Collision detected!" << std::endl;
}