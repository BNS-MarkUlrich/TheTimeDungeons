#include "Player.h"
#include <iostream>

Player::Player() {
    // Initialize player properties, including SFML shape
    currentPosition = sf::Vector2f(50, 50);
    movementSpeed = 10.0f;
}

void Player::update(sf::Time deltaTime) {
    // Update logic for the player, including movement and collision detection
}

void Player::draw(sf::RenderWindow& window) 
{
    //currentPosition = sf::Vector2f(50, 50); // Set the position of the player
    shape.setPosition(currentPosition); // Set the position of the player shape
    shape.setFillColor(sf::Color::Green); // Set the color of the player shape
    shape.setRadius(10.0f); // Set the radius of the player shape
    window.draw(shape); // Draw the player shape
}

sf::Vector2f Player::getPosition() {
	// Return the position of the player
    return currentPosition;
}

void Player::parseInput(const std::string& input) {
	std::vector<std::string> commands = inputParser.parseInput(input);
    std::cout << "Parsing Input: " << commands[0] << std::endl;
	processInput(commands);
}

void Player::processInput(const std::vector<std::string>& commands) {
    if (!commands.empty()) {
        if (commands[0] == "w") {
            move("Up");
        }
        if (commands[0] == "s") {
			move("Down");
		}
        if (commands[0] == "a") {
            move("Left");
        }
        if (commands[0] == "d") {
			move("Right");
		}

        // Add more commands as needed
    }
}

void Player::move(const std::string& direction) {
    // Implement movement logic
    std::cout << "Moving " << direction << std::endl;

    if (direction == "Up") {
		currentPosition.y -= movementSpeed;
	}
    if (direction == "Down") {
		currentPosition.y += movementSpeed;
	}
    if (direction == "Left") {
		currentPosition.x -= movementSpeed;
	}
    if (direction == "Right") {
		currentPosition.x += movementSpeed;
	}
}