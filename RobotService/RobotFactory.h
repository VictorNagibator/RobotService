#pragma once
#include "IRobot.h"

class RobotFactory
{
public:
	virtual IRobot* createRobot(int id, std::string name) = 0;
};