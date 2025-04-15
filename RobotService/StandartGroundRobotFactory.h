#pragma once
#include "RobotFactory.h"
#include "CellularChannelPool.h"

class StandartGroundRobotFactory :
    public RobotFactory
{
private:
	CellularChannelPool* channelPool; //ƒопустим, что одна фабрика отпускает роботов дл€ одной и той же вышки св€зи
public:
	StandartGroundRobotFactory();
	~StandartGroundRobotFactory();

	IRobot* createRobot(int id, std::string name) override;
};