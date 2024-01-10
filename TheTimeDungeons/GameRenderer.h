#pragma once  // Use pragma once for header guards to prevent multiple inclusions

#include <SFML/Graphics.hpp>

class GameRenderer : public sf::RenderWindow
{
public:
    GameRenderer(sf::Vector2f targetResolution);
    ~GameRenderer();
    void renderWindow();
    void setResolution(sf::Vector2f newResolution);

private:
    sf::Vector2f resolution;
    sf::RenderWindow window;
    sf::CircleShape circle;
};
