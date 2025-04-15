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
    //���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "\n--- ��������� ����� ---\n";
    //������ �����
    IEnvironment* groundEnv = new GroundEnvironment();

    //������� ��� �������� ����������������
    EngineFactory* electricFactory = new ElectricMotorFactory();
    IEngine* engine = electricFactory->createEngine("EM-FM-01", 2000, 90, groundEnv);
    engine->start(); //��������� ��������
    engine->stop();
    delete engine;
	engine = electricFactory->createEngine("EM-FM-02", 2500, 90, groundEnv); //������� ������� ����� ���������
    engine->start(); 
    engine->stop();
    delete engine;
    delete electricFactory;

    std::cout << "\n--- ����������� ������� ---\n";
    //������������� ����������� ������� (��������, StandartGroundRobotFactory) ��� �������� ������
    RobotFactory* robotFactory = new StandartGroundRobotFactory();
    IRobot* robotPrototype = robotFactory->createRobot(1, "�������� �����");
    robotPrototype->startDelivery("��. ������, 3");
    robotPrototype->stopDelivery();
    delete robotFactory;
    //� �������� �����
    robotFactory = new StandartDroneFactory();
	IRobot* dronePrototype = robotFactory->createRobot(2, "����");
	dronePrototype->startDelivery("��. ����������, 10");
    robotPrototype->stopDelivery();
    //(����� ������������� ������ �������, ������ ����� �������������� �����)
    delete robotFactory;

    std::cout << "\n--- �������� ---\n";
    //������� ������� ������� � ��������� ������-�������� � ����
    IAggregate<IRobot*>* robotAggregate = new MyList<IRobot*>;
    robotAggregate->push(robotPrototype);
	robotAggregate->push(dronePrototype);

    //�������� ����������� ����������
    CentralController* controller = CentralController::getInstance("MainController", robotAggregate);
    controller->monitorRobots();
    //������� ��� ���� ���������
	CentralController* controller_another = CentralController::getInstance();
    controller_another->monitorRobots(); //�����, ��� ��� �� ����� ����������
    delete controller;

    std::cout << "\n--- �������� ---\n";
    IRobot* robotClone = robotPrototype->clone();
    robotClone->startDelivery("��. ������, 1");
    robotClone->stopDelivery();

    //������ ���������, ��� ��� ���������� �������� �����������
	robotClone->checkStatus();
    robotPrototype->checkStatus();
    delete robotClone;

    std::cout << "\n--- ��������� ��� ---\n";
    //������ �������� �����, ������� ���������� ��� �����
	CellularChannelPool* pool = new CellularChannelPool(3); //��� �� 3 ������� 
    ICommunication* cellularComm1 = new CellularCommunication(100, 10, groundEnv, pool);
    ICommunication* cellularComm2 = new CellularCommunication(150, 20, groundEnv, pool);
    ICommunication* cellularComm3 = new CellularCommunication(100, 30, groundEnv, pool);
    ICommunication* cellularComm4 = new CellularCommunication(100, 40, groundEnv, pool);

    //������� ������� ��� ���� ����������
	cellularComm1->establishConnection();
    cellularComm1->sendData("������ 1");
	cellularComm2->establishConnection();
    cellularComm2->sendData("������ 2");
	cellularComm3->establishConnection();
    cellularComm3->sendData("������ 3");

    //��� 4-�� ��� �� ������
	cellularComm4->establishConnection(); //�����: ��� ��������� �������

    //�� ����������, ��������, �� ������ ������
    cellularComm1->disconnect();
	//������ 4-� ������ ������������
	cellularComm4->establishConnection(); //������ ��� ��������
    cellularComm4->sendData("������ 4!");

	delete cellularComm1;
    delete cellularComm2;
	delete cellularComm3;
    delete cellularComm4;

    std::cout << "\n--- ��������� + �������� ---\n";
    //������� ��������� ��� MapSegment (� ��������� �������������)
    DetailedMapSegmentBuilder* mapBuilder = new DetailedMapSegmentBuilder();
    //������� ��������� ��� ������ ����������� ����� (� ��������������� ����������)
    AdvancedMapDirector* advancedDirector = new AdvancedMapDirector(mapBuilder);
    MapSegment* detailedMap = advancedDirector->constructMap();
    detailedMap->printMapInfo();

    //���������� ���������� ����� � ������������� �������
    INavigation* navigation = new GPSNavigation(groundEnv, detailedMap, 10, 2);
    navigation->navigate("��. ������, 2");
    navigation->updatePosition(10.0, 20.0);
    navigation->adjustRoute();

    //������ ������
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