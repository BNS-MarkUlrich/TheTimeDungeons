#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/System/Vector2.hpp>
#include "Collider.h"
#include "GameObject.h"

class Enemy : public Collider {
public:
	Enemy();
	void start();
	void update();
	void fixedUpdate(sf::Time deltaTime); // Update player's state
	void draw(sf::RenderWindow& window); // Draw the player

	// Other player methods and properties
	//Room currentRoom;

private:
	void OnCollisionStart(const Collider& other) const override;
};

#endif