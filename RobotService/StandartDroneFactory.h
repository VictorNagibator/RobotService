#pragma once
#include "RobotFactory.h"
class StandartDroneFactory :
    public RobotFactory
{
public:
	IRobot* createRobot(int id, std::string name) override;
};