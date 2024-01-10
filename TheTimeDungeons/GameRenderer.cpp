#include <iostream>
#include "GameRenderer.h"
#include "PhysicsEngine.h"

GameRenderer::GameRenderer(sf::Vector2f targetResolution)
{
    setResolution(sf::Vector2f(targetResolution.x, targetResolution.y));
    window.create(sf::VideoMode(resolution.x, resolution.y), "SFML Circle Window");
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color::White);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(resolution.x / 2.f, resolution.y / 2.f);
}

GameRenderer::~GameRenderer()
{
}

void GameRenderer::setResolution(sf::Vector2f newResolution)
{
	resolution = newResolution;
}

void GameRenderer::renderWindow() 
{
    while (window.isOpen()) {
        /*sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }*/

        window.clear();
        window.draw(circle);
        window.display();
        window.setSize(sf::Vector2u(resolution.x, resolution.y));

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        sf::Vector2f mousePosWorld = window.mapPixelToCoords(sf::Vector2i(mousePos.x, mousePos.y));
        circle.setPosition(mousePosWorld);
    }
}
