#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "The Time Dungeons"), dungeon(10, 10), player(/* player initialization */) {
    // Initialize the view to the size of the window
    view.setSize(800, 600);

    start();
}

void Game::start()
{
    std::cout << "Game started" << std::endl;

    player.currentRoom = dungeon.getCurrentRoom();
	player.start();
}

void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        processEvents();
        deltaTime += clock.getElapsedTime();
        if (deltaTime.asSeconds() >= 0.02) {
            // Call the fixedUpdate method
            fixedUpdate(deltaTime);
            deltaTime = clock.restart();
        }
        update();
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
    }
}

void Game::update() 
{
    // Update is called before every rendered frame.
    player.update();
}

void Game::fixedUpdate(sf::Time deltaTime)
{
    // Fixed update is called at a fixed time step, meaning it called independently from the current framerate.
    player.fixedUpdate(deltaTime);

    //view.setCenter(player.getPosition());
}

void Game::render() 
{
    window.setView(view);

    window.clear();

    dungeon.getCurrentRoom().draw(window);
    player.draw(window);
    view.setCenter(dungeon.getCurrentRoom().getCenter());
    
    window.display();
}
