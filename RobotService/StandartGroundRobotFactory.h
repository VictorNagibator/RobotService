#pragma once
#include "RobotFactory.h"

class StandartGroundRobotFactory :
    public RobotFactory
{
public:
	IRobot* createRobot(int id, std::string name) override;
};