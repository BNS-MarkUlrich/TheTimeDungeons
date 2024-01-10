#include "MainGame.h"
#include "GameRenderer.h"
#include "PhysicsEngine.h"
#include "PhysicsObject.h"
#include "BallTest.h"

void renderThreadBehaviour()
{
    
}

void physicsThreadBehaviour()
{
	
}

int main() 
{
    sf::Vector2f windowSize(800, 600);
    GameRenderer app(windowSize);
    app.renderWindow();

    PhysicsEngine physicsEngine;

    BallTest ball;
    ball.setRadius(50);
    ball.setPosition(sf::Vector2f(100, 100));
    ball.setAcceleration(sf::Vector2f(0, 100));

    while (physicsEngine.fixedUpdate())
    {
        ball.updatePhysicsBody(physicsEngine.deltaTime);
    }

    return 0;
}
