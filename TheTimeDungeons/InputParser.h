#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "Action.cpp"

class InputParser {
public:
    InputParser();
    sf::Vector2f getMoveDirection();
    bool isKeyPressed(Action action);

private:
	void InitKeyBindings();
    std::map<Action, sf::Keyboard::Key> keyBindings;
};

#endif