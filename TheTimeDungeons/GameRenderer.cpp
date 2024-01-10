#include "GameRenderer.h"

// Define the constructor outside the class declaration
GameRenderer::GameRenderer() {
    window.create(sf::VideoMode(400, 400), "SFML Circle Window");
    circle.setRadius(50.f);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(175.f, 175.f);
}

void GameRenderer::renderWindow() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
}
