#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class MathUtils {
public:
	static float lerp(float startValue, float endValue, sf::Time elapsedTime, sf::Time totalTime);
	static sf::Vector2f lerp(sf::Vector2f startValue, sf::Vector2f endValue, sf::Time elapsedTime, sf::Time totalTime);
};