#include <SFML/Graphics.hpp>
#include <unordered_set>

class GameObject
{
public:
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual void draw(sf::RenderTarget& window) const = 0;

    bool isColliding(const GameObject& shape, const std::unordered_set<const GameObject*>& objects);
    const GameObject* getCollidingObject(const GameObject& shape, const std::unordered_set<const GameObject*>& objects);
};
