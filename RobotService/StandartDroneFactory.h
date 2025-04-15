#pragma once
#include "RobotFactory.h"
#include "CellularChannelPool.h"

class StandartDroneFactory :
    public RobotFactory
{
private:
	CellularChannelPool* channelPool; //ƒопустим, что одна фабрика отпускает роботов дл€ одной и той же вышки св€зи
public:
	StandartDroneFactory();
	~StandartDroneFactory();

	IRobot* createRobot(int id, std::string name) override;
};