#include "StandartDroneFactory.h"
#include "Drone.h"
#include "ElectricMotorFactory.h"
#include "BatteryFactory.h"
#include "GPSNavigationFactory.h"
#include "CellularCommunicationFactory.h"
#include "AirEnvironment.h"

IRobot* StandartDroneFactory::createRobot(int id, std::string name)
{
	//������� ��������� �����
	IEnvironment* environment = new AirEnvironment();

	//������� ������� ������������ ����� ��������� �����
	ElectricMotorFactory motorFactory;
	IEngine* engine = motorFactory.createEngine("EL-01-AIR-X", 6000, 100, environment);

	//���������� ������� �����������
	BatteryFactory batteryFactory(10000); //���������� ������ ����� ����������� ������� �������
	IPowerSource* powerSource = batteryFactory.createPowerSource(environment);

	//������� ��������� � ����� ��� �����
	GPSNavigationFactory navigationFactory;
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory;
	ICommunication* communication = communicationFactory.createCommunication(50, environment);

	//���������� ��������� �������� ������� - ��� �������, ��� � ������������
	return new Drone(id, name, engine, navigation, communication, powerSource);
}