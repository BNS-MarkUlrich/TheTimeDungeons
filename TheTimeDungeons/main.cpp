#include "Game.h"

int main()
{
    Game game;
    game.run();
    return 0;
}

//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <unordered_set>
//#include <iostream>
//
//// Base class for game objects
//class GameObject {
//public:
//    virtual sf::FloatRect getGlobalBounds() const = 0;
//    virtual void draw(sf::RenderTarget& target) const = 0;
//};
//
//const GameObject* getCollidingObject(const GameObject& shape, const std::unordered_set<const GameObject*>& objects) {
//    for (const auto& object : objects) {
//        if (&shape != object && shape.getGlobalBounds().intersects(object->getGlobalBounds())) {
//            return object;
//        }
//    }
//    return nullptr;
//}
//
//// Specific object types
//class RectangleShapeObject : public GameObject {
//private:
//    sf::RectangleShape shape;
//
//public:
//    RectangleShapeObject(sf::Vector2f size, sf::Color color, sf::Vector2f position) : shape(size) {
//        shape.setFillColor(color);
//        shape.setPosition(position);
//    }
//
//    sf::FloatRect getGlobalBounds() const override { return shape.getGlobalBounds(); }
//    void draw(sf::RenderTarget& target) const override { target.draw(shape); }
//};
//
//class CircleShapeObject : public GameObject {
//private:
//    sf::CircleShape shape;
//
//public:
//    CircleShapeObject(float radius, sf::Color color, sf::Vector2f position) : shape(radius) {
//        shape.setFillColor(color);
//        shape.setPosition(position);
//        shape.setOrigin(radius, radius); // Center origin
//    }
//
//    sf::FloatRect getGlobalBounds() const override { return shape.getGlobalBounds(); }
//    void draw(sf::RenderTarget& target) const override { target.draw(shape); }
//};
//
//// Function to check if a shape collides with any object in a set
//bool isColliding(const GameObject& shape, const std::unordered_set<const GameObject*>& objects) {
//    for (const auto& object : objects) {
//        if (&shape != object && shape.getGlobalBounds().intersects(object->getGlobalBounds())) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Dynamic Collision Detection");
//
//    // Create a player shape
//    RectangleShapeObject player(sf::Vector2f(50, 50), sf::Color::White, sf::Vector2f(400, 150));
//
//    // Create a set to store obstacle shapes
//    std::unordered_set<const GameObject*> obstacles;
//    obstacles.insert(new RectangleShapeObject(sf::Vector2f(100, 100), sf::Color::Blue, sf::Vector2f(300, 200)));
//    obstacles.insert(new CircleShapeObject(50.f, sf::Color::Green, sf::Vector2f(500, 150)));
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        const GameObject* collidingObject = getCollidingObject(player, obstacles);
//        if (collidingObject) {
//            // Handle collision
//            std::cout << "Colliding with obstacle: " << typeid(*collidingObject).name() << std::endl;
//        }
//
//        window.clear();
//        player.draw(window);
//        for (const auto& object : obstacles) {
//            object->draw(window);
//        }
//        window.display();
//    }
//
//    return 0;
//}
