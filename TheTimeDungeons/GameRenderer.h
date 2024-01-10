#pragma once  // Use pragma once for header guards to prevent multiple inclusions

#include <SFML/Graphics.hpp>

class GameRenderer {
public:
    GameRenderer(); // Declaration of the constructor
    void renderWindow();

private:
    sf::RenderWindow window;
    sf::CircleShape circle;
};
