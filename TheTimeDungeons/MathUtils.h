#include <SFML/System/Time.hpp>

class MathUtils {
public:
	static float lerp(float startValue, float endValue, sf::Time elapsedTime, sf::Time totalTime);
};