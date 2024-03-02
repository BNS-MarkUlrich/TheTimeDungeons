#include "MathUtils.h"
#include <utility>

float MathUtils::lerp(float startValue, float endValue, sf::Time elapsedTime, sf::Time totalTime) {
	// Avoid division by zero
	if (totalTime.asSeconds() == 0.f) {
		return endValue;
	}

	// Calculate the interpolation factor (0.0 to 1.0)
	float lerpFactor = static_cast<float>(elapsedTime.asMicroseconds()) / static_cast<float>(totalTime.asMicroseconds());

	// Clamp the factor between 0 and 1
	lerpFactor = std::min(std::max(lerpFactor, 0.f), 1.f);

	// Lerp between the values
	return startValue + lerpFactor * (endValue - startValue);
}