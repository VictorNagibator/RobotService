#pragma once
#include "RobotFactory.h"
#include "CellularChannelPool.h"

class StandartDroneFactory :
    public RobotFactory
{
private:
	CellularChannelPool* channelPool; //��������, ��� ���� ������� ��������� ������� ��� ����� � ��� �� ����� �����
public:
	StandartDroneFactory();
	~StandartDroneFactory();

	IRobot* createRobot(int id, std::string name) override;
};