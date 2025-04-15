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
	channelPool = new CellularChannelPool(3); //Создаем пул каналов связи (для демонстрации)
}

StandartDroneFactory::~StandartDroneFactory()
{
	delete channelPool; //Освобождаем память
}

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
	powerSource->recharge();

	//Создаем навигацию и связь для дрона

	//Для летного дрона будем использовать обычного директора для построения карты
	//(летным дронам можно знать лишь улицы и дома, но необязательно пешеходные переходы и светофоры)
	DetailedMapSegmentBuilder builder;
	BasicMapDirector director(&builder);

	MapSegment* map = director.constructMap(); //Создаем карту

	GPSNavigationFactory navigationFactory(map); //Передаем её при создании навигации
	INavigation* navigation = navigationFactory.createNavigation(environment);
	CellularCommunicationFactory communicationFactory(channelPool); //У всех роботов с одной фабрики будет один и тот же пул
	ICommunication* communication = communicationFactory.createCommunication(50, environment);

	//Управление объектами передаем клиенту - как роботом, так и компонентами
	return new Drone(id, name, engine, navigation, communication, powerSource);
}