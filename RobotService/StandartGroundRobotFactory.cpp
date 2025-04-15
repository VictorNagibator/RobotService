#include "StandartGroundRobotFactory.h"
#include "SimpleRobot.h"
#include "HybridEngineFactory.h"
#include "BatteryFactory.h"
#include "LidarNavigationFactory.h"
#include "CellularCommunicationFactory.h"
#include "GroundEnvironment.h"

StandartGroundRobotFactory::StandartGroundRobotFactory()
{
	channelPool = new CellularChannelPool(5); //Создаем пул каналов связи (для демонстрации)
}

StandartGroundRobotFactory::~StandartGroundRobotFactory()
{
	delete channelPool; //Освобождаем память
}

IRobot* StandartGroundRobotFactory::createRobot(int id, std::string name)
{
	//Создаем наземную среду
	IEnvironment* environment = new GroundEnvironment();

	//Создаем обычный гибридный двигатель через фабричный метод
	HybridEngineFactory motorFactory;
	IEngine* engine = motorFactory.createEngine("HY-01", 5000, 90, environment);

	//Аналогично создаем аккумулятор
	BatteryFactory batteryFactory;
	IPowerSource* powerSource = batteryFactory.createPowerSource(environment);
	powerSource->recharge();

	//Создаем навигацию и связь
	LidarNavigationFactory navigationFactory;
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory(channelPool); //У всех роботов с одной фабрики будет один и тот же пул
	ICommunication* communication = communicationFactory.createCommunication(100, environment);

	//Управление объектами передаем клиенту - как роботом, так и компонентами
	return new SimpleRobot(id, name, engine, navigation, communication, powerSource);
}