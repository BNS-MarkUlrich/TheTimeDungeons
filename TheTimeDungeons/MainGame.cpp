#include "MainGame.h"
#include "GameRenderer.h"
#include <iostream>
using namespace sf;

int main() 
{
    sf::Vector2f windowSize(800, 600);
    GameRenderer app(windowSize);
    app.create(sf::VideoMode(windowSize.x, windowSize.y), "The Time Dungeons");

    CircleShape circle = sf::CircleShape(50.f);
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color::White);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
    

    while (app.isOpen()) {
        sf::Event event;
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(circle);
        app.display();
        app.setSize(sf::Vector2u(windowSize.x, windowSize.y));

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(app));
        sf::Vector2f mousePosWorld = app.mapPixelToCoords(sf::Vector2i(mousePos.x, mousePos.y));
        circle.setPosition(mousePosWorld);
    }

    return 0;
}
