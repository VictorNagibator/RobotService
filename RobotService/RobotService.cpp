#pragma once
#include <iostream>
#include <windows.h>

#include "GroundEnvironment.h"             
#include "AirEnvironment.h"               
#include "GPSNavigation.h"               
#include "ElectricMotorFactory.h"           
#include "StandartGroundRobotFactory.h"      
#include "CentralController.h"      
#include "MyList.h"                          
#include "BasicRobotExpert.h"                
#include "RobotManager.h"                    
#include "DetailedMapSegmentBuilder.h"       
#include "AdvancedMapDirector.h"            
#include "StreetSegmentFactory.h"                     
#include "SimpleRobot.h"    
#include "StandartDroneFactory.h"
#include "CellularCommunication.h"

int main() {
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "\n--- Фабричный метод ---\n";
    //оздаем среду
    IEnvironment* groundEnv = new GroundEnvironment();

    //Фабрика для создания электродвигателя
    EngineFactory* electricFactory = new ElectricMotorFactory();
    IEngine* engine = electricFactory->createEngine("EM-FM-01", 2000, 90, groundEnv);
    engine->start(); //Двигатель работает
    engine->stop();
    delete engine;
	engine = electricFactory->createEngine("EM-FM-02", 2500, 90, groundEnv); //Фабрика создает новый двигатель
    engine->start(); 
    engine->stop();
    delete engine;
    delete electricFactory;

    std::cout << "\n--- Абстрактная фабрика ---\n";
    //Использование абстрактной фабрики (например, StandartGroundRobotFactory) для создания робота
    RobotFactory* robotFactory = new StandartGroundRobotFactory();
    IRobot* robotPrototype = robotFactory->createRobot(1, "Наземный робот");
    robotPrototype->startDelivery("пр. Ленина, 3");
    robotPrototype->stopDelivery();
    delete robotFactory;
    //И создадим дрона
    robotFactory = new StandartDroneFactory();
	IRobot* dronePrototype = robotFactory->createRobot(2, "Дрон");
	dronePrototype->startDelivery("ул. Молодежная, 10");
    robotPrototype->stopDelivery();
    //(После использования удалим фабрику, роботы будут использоваться далее)
    delete robotFactory;

    std::cout << "\n--- Одиночка ---\n";
    //Создаем агрегат роботов и добавляем робота-прототип в него
    IAggregate<IRobot*>* robotAggregate = new MyList<IRobot*>;
    robotAggregate->push(robotPrototype);
	robotAggregate->push(dronePrototype);

    //Получаем центральный контроллер
    CentralController* controller = CentralController::getInstance("MainController", robotAggregate);
    controller->monitorRobots();
    //Пробуем еще один запросить
	CentralController* controller_another = CentralController::getInstance();
    controller_another->monitorRobots(); //Видно, что тот же самый контроллер
    delete controller;

    std::cout << "\n--- Прототип ---\n";
    IRobot* robotClone = robotPrototype->clone();
    robotClone->startDelivery("ул. Ленина, 1");
    robotClone->stopDelivery();

    //Разное состояние, так как происходит глубокое копирование
	robotClone->checkStatus();
    robotPrototype->checkStatus();
    delete robotClone;

    std::cout << "\n--- Объектный пул ---\n";
    //Создаём средство связи, которое использует пул связи
	CellularChannelPool* pool = new CellularChannelPool(3); //Пул из 3 каналов 
    ICommunication* cellularComm1 = new CellularCommunication(100, 10, groundEnv, pool);
    ICommunication* cellularComm2 = new CellularCommunication(150, 20, groundEnv, pool);
    ICommunication* cellularComm3 = new CellularCommunication(100, 30, groundEnv, pool);
    ICommunication* cellularComm4 = new CellularCommunication(100, 40, groundEnv, pool);

    //Пробуем открыть для трех соединения
	cellularComm1->establishConnection();
    cellularComm1->sendData("Пример 1");
	cellularComm2->establishConnection();
    cellularComm2->sendData("Пример 2");
	cellularComm3->establishConnection();
    cellularComm3->sendData("Пример 3");

    //Для 4-го уже не хватит
	cellularComm4->establishConnection(); //Вывод: нет доступных каналов

    //Но отключимся, например, на первом канале
    cellularComm1->disconnect();
	//Теперь 4-й сможет подключиться
	cellularComm4->establishConnection(); //Теперь все работает
    cellularComm4->sendData("Пример 4!");

	delete cellularComm1;
    delete cellularComm2;
	delete cellularComm3;
    delete cellularComm4;

    std::cout << "\n--- Строитель + Директор ---\n";
    //Создаем строителя для MapSegment (с детальной конфигурацией)
    DetailedMapSegmentBuilder* mapBuilder = new DetailedMapSegmentBuilder();
    //Создаем директора для сборки расширенной карты (с дополнительными элементами)
    AdvancedMapDirector* advancedDirector = new AdvancedMapDirector(mapBuilder);
    MapSegment* detailedMap = advancedDirector->constructMap();
    detailedMap->printMapInfo();

    //Встраиваем полученную карту в навигационную систему
    INavigation* navigation = new GPSNavigation(groundEnv, detailedMap, 10, 2);
    navigation->navigate("пр. Ленина, 2");
    navigation->updatePosition(10.0, 20.0);
    navigation->adjustRoute();

    //Чистим память
	delete navigation;
	delete detailedMap;
	delete advancedDirector;
	delete mapBuilder;
	delete robotAggregate;
    delete robotPrototype;
    delete dronePrototype;
	delete groundEnv;

    return 0;
}