#pragma once
#include <iostream>
#include <chrono>
#include <thread>

class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	bool update();
	bool fixedUpdate();

    double getElapsedTime(int delayInMiliseconds);

    void delayForMilliseconds(int milliseconds) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }

    float deltaTime;

private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    float fixedTimeStep;
    float lastTime;
};

