#pragma once
#include "RobotFactory.h"
#include "CellularChannelPool.h"

class StandartGroundRobotFactory :
    public RobotFactory
{
private:
	CellularChannelPool* channelPool; //��������, ��� ���� ������� ��������� ������� ��� ����� � ��� �� ����� �����
public:
	StandartGroundRobotFactory();
	~StandartGroundRobotFactory();

	IRobot* createRobot(int id, std::string name) override;
};