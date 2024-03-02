#include "GameObject.h"

bool GameObject::isColliding(const GameObject& shape, const std::unordered_set<const GameObject*>& objects) {
	for (const auto& object : objects) {
		if (&shape != object && shape.getGlobalBounds().intersects(object->getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

const GameObject* GameObject::getCollidingObject(const GameObject& shape, const std::unordered_set<const GameObject*>& objects) {
	for (const auto& object : objects) {
		if (object->getGlobalBounds().intersects(shape.getGlobalBounds())) {
			return object;
		}
	}
	return nullptr;
}