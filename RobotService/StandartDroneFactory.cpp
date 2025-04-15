#include "StandartDroneFactory.h"
#include "Drone.h"
#include "ElectricMotorFactory.h"
#include "BatteryFactory.h"
#include "GPSNavigationFactory.h"
#include "CellularCommunicationFactory.h"
#include "AirEnvironment.h"

IRobot* StandartDroneFactory::createRobot(int id, std::string name)
{
	//Создаем воздушную среду
	IEnvironment* environment = new AirEnvironment();

	//Создаем обычный электромотор через фабричный метод
	ElectricMotorFactory motorFactory;
	IEngine* engine = motorFactory.createEngine("EL-01-AIR-X", 6000, 100, environment);

	//Аналогично создаем аккумулятор
	BatteryFactory batteryFactory(10000); //Воздушному роботу нужен аккумулятор большей емкости
	IPowerSource* powerSource = batteryFactory.createPowerSource(environment);

	//Создаем навигацию и связь для дрона
	GPSNavigationFactory navigationFactory;
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory;
	ICommunication* communication = communicationFactory.createCommunication(50, environment);

	//Управление объектами передаем клиенту - как роботом, так и компонентами
	return new Drone(id, name, engine, navigation, communication, powerSource);
}