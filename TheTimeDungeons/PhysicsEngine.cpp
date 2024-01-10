#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine()
{
	deltaTime = 0;
	fixedTimeStep = 0.016f;
	lastTime = 0;
}

PhysicsEngine::~PhysicsEngine()
{
}

bool PhysicsEngine::update()
{
	return true;
}

bool PhysicsEngine::fixedUpdate()
{
	// Get the time since the last frame
	float currentTime = getElapsedTime(100);
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	// If the time since the last frame is greater than the fixed time step, update the physics engine
	if (deltaTime >= fixedTimeStep)
	{
		deltaTime = 0;
		lastTime = 0;
		fixedUpdate();
		return true;
	}

	return false;
}

double PhysicsEngine::getElapsedTime(int delayInMiliseconds)
{
	TimePoint startTime = Clock::now();

	delayForMilliseconds(delayInMiliseconds);

	TimePoint endTime = Clock::now();
	std::chrono::duration<double> elapsed = endTime - startTime;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";

	return elapsed.count();
}
