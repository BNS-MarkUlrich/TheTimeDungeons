#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Game Title"), dungeon(10, 10), player(/* player initialization */) {
    // Initialize the view to the size of the window
    view.setSize(800, 600);
}

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
    std::string input;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                char pressedKey = static_cast<char>(event.text.unicode);
                //std::cout << "Pressed key: " << pressedKey << std::endl;

                input += pressedKey;

                player.parseInput(input);
                input.clear(); // Clear input for next command
            }
        }
    }
}

void Game::update(sf::Time deltaTime) 
{
    player.update(deltaTime);

    view.setCenter(player.getPosition());
}

void Game::render() 
{
    window.setView(view);

    window.clear();
    dungeon.getCurrentRoom().draw(window);
    player.draw(window);
    window.display();
}
