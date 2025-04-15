#include "StandartDroneFactory.h"
#include "Drone.h"
#include "ElectricMotorFactory.h"
#include "BatteryFactory.h"
#include "GPSNavigationFactory.h"
#include "CellularCommunicationFactory.h"
#include "AirEnvironment.h"
#include "BasicMapDirector.h"
#include "DetailedMapSegmentBuilder.h"

StandartDroneFactory::StandartDroneFactory()
{
	channelPool = new CellularChannelPool(3); //������� ��� ������� ����� (��� ������������)
}

StandartDroneFactory::~StandartDroneFactory()
{
	delete channelPool; //����������� ������
}

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
	powerSource->recharge();

	//������� ��������� � ����� ��� �����

	//��� ������� ����� ����� ������������ �������� ��������� ��� ���������� �����
	//(������ ������ ����� ����� ���� ����� � ����, �� ������������� ���������� �������� � ���������)
	DetailedMapSegmentBuilder builder;
	BasicMapDirector director(&builder);

	MapSegment* map = director.constructMap(); //������� �����

	GPSNavigationFactory navigationFactory(map); //�������� � ��� �������� ���������
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory(channelPool); //� ���� ������� � ����� ������� ����� ���� � ��� �� ���
	ICommunication* communication = communicationFactory.createCommunication(50, environment);

	//���������� ��������� �������� ������� - ��� �������, ��� � ������������
	return new Drone(id, name, engine, navigation, communication, powerSource);
}