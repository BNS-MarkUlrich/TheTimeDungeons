#include "InputParser.h"
#include <sstream>
#include <iostream>

InputParser::InputParser() {
    InitKeyBindings();
}

void InputParser::InitKeyBindings() {
    keyBindings[Action::MoveUp] = sf::Keyboard::W;
	keyBindings[Action::MoveDown] = sf::Keyboard::S;
	keyBindings[Action::MoveLeft] = sf::Keyboard::A;
	keyBindings[Action::MoveRight] = sf::Keyboard::D;
	keyBindings[Action::Attack] = sf::Keyboard::Space;
	keyBindings[Action::None] = sf::Keyboard::Unknown;
}

sf::Vector2f InputParser::getMoveDirection() {
    sf::Vector2f direction;

    if (sf::Keyboard::isKeyPressed(keyBindings[Action::MoveUp])) {
		direction.y = -1;
	}
    if (sf::Keyboard::isKeyPressed(keyBindings[Action::MoveDown])) {
		direction.y = 1;
	}
    if (sf::Keyboard::isKeyPressed(keyBindings[Action::MoveLeft])) {
		direction.x = -1;
	}
    if (sf::Keyboard::isKeyPressed(keyBindings[Action::MoveRight])) {
		direction.x = 1;
	}

	return direction;
}