#include "StandartGroundRobotFactory.h"
#include "SimpleRobot.h"
#include "HybridEngineFactory.h"
#include "BatteryFactory.h"
#include "LidarNavigationFactory.h"
#include "CellularCommunicationFactory.h"
#include "GroundEnvironment.h"

IRobot* StandartGroundRobotFactory::createRobot(int id, std::string name)
{
	//������� �������� �����
	IEnvironment* environment = new GroundEnvironment();

	//������� ������� ��������� ��������� ����� ��������� �����
	HybridEngineFactory motorFactory;
	IEngine* engine = motorFactory.createEngine("HY-01", 5000, 90, environment);

	//���������� ������� �����������
	BatteryFactory batteryFactory;
	IPowerSource* powerSource = batteryFactory.createPowerSource(environment);

	//������� ��������� � �����
	LidarNavigationFactory navigationFactory;
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory;
	ICommunication* communication = communicationFactory.createCommunication(100, environment);

	//���������� ��������� �������� ������� - ��� �������, ��� � ������������
	return new SimpleRobot(id, name, engine, navigation, communication, powerSource);
}