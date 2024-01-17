#include "Game.h"

void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time deltaTime) 
{
    player.update(deltaTime);
}

void Game::render() 
{
    window.clear();
    sf::Vector2f size = sf::Vector2f(500,500);
    Room currentRoom = Room(size);
    currentRoom.draw(window);
    player.draw(window);
    window.display();
}
