#include <iostream>
#include <windows.h>
#include "ElectricMotor.h"
#include "ProxyEngine.h"
#include "GPSNavigation.h"
#include "WiFiCommunication.h"
#include "Battery.h"
#include "GroundRobot.h"
#include "CombustionEngine.h"
#include "VisionNavigation.h"
#include "LTECommunication.h"
#include "FuelCell.h"
#include "Drone.h"
#include "CentralController.h"
#include "MyList.h"
#include "ProxyIterator.h"
#include "YandexNavigationAdapter.h"
#include "CommunicationEncryptorDecorator.h"
#include "CommunicationTimestampDecorator.h"
#include "CommunicationPrinterDecorator.h"
#include "RobotGroup.h"
#include "HybridEngine.h"

int main() {
    //���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== ������������ �������� ===\n";
	IEngine* grElectricMotor = new ElectricMotor("EM-GR-01", 500, 75);
	INavigation* grNavigation = new YandexNavigationAdapter(1, 1); //������� �������
	ICommunication* grWiFi = new WiFiCommunication(45, 6);
	IPowerSource* grBattery = new Battery(3000);
    //���������� ��� ��� ������!
	GroundRobot robot1 = GroundRobot(1, "Model-X", grElectricMotor, grNavigation, grWiFi, grBattery);
    //���������������� ������ �������� ����� ������ ��������
	grBattery->recharge();
	robot1.startDelivery("����� ������, 5");

    std::cout << "\n=== ������������ ����������� ��� ICommunication � ������ �������� ===\n";
    //���� ������������ ����� WiFi, ��������� ����
    //������� 1
    ICommunication* comm1 = new CommunicationEncryptorDecorator(grWiFi);
    ICommunication* comm2 = new CommunicationTimestampDecorator(comm1);
    ICommunication* comm3 = new CommunicationPrinterDecorator(comm2);

    std::cout << "\n--- ������� 1: ����� �� ����� -> ����� ������� -> ���������� ---\n";
    //�������� ��� ������ ������, �� � ������ ��������� ������������
    GroundRobot robot2 = GroundRobot(2, "Model-X-DECORATED", grElectricMotor, grNavigation, comm3, grBattery);
    robot2.startDelivery("����� ����������, 61");

    //������� 2
    ICommunication* gr4G = new LTECommunication(45, 50);
    ICommunication* comm4 = new CommunicationPrinterDecorator(gr4G);
    ICommunication* comm5 = new CommunicationTimestampDecorator(comm4);
    ICommunication* comm6 = new CommunicationEncryptorDecorator(comm5);

    std::cout << "\n--- ������� 2: ���������� -> ����� ������� -> ����� �� ����� ---\n";
    //������ �����
    GroundRobot robot3 = GroundRobot(3, "Model-X-DECORATED-v 2.0", grElectricMotor, grNavigation, comm6, grBattery);
    robot3.startDelivery("����� ����������, 62");

    std::cout << "\n=== ������������ ��������� (RobotGroup) ===\n";
    //������� ���� ����� ��������� ������� � ������� ������ �������
	IAggregate<IRobot*>* groupAggregate1 = new MyList<IRobot*>; //������� ������� ��� ������
    RobotGroup* group1 = new RobotGroup(groupAggregate1);
    group1->addRobot(&robot2);
    group1->addRobot(&robot3);

    //������� ������ ������ � �������� � �� ��� ������ ������ � ������ ������ 
    //(������������ ��������� �����)
    IAggregate<IRobot*>* groupAggregate2 = new MyList<IRobot*>;
    RobotGroup* group2 = new RobotGroup(groupAggregate2);
    group2->addRobot(&robot1);
    group2->addRobot(group1);

    //��������� �������� ��� ���� ������ 
    group2->startDelivery("����� �1");
    group2->stopDelivery();
    group2->checkStatus();

    std::cout << "\n=== ������������ ��������� �������� � � ����������� ����������� ===\n";
    //������� ������� ������� � ������� MyList
    MyList<IRobot*>* robotList = new MyList<IRobot*>;
    robotList->push(&robot3);
    robotList->push(&robot1);
    robotList->push(&robot2);

    std::cout << "\n����� ������ ������� ����� ��������:\n";
    ProxyIterator<IRobot*> proxyIt(robotList->begin()); //���������� ������, ����� ����� �� ������� ������
    while (proxyIt.hasNext()) {
        IRobot* robot = *(proxyIt.next());
        robot->checkStatus(); //��������� ��������� �������, ��������
    }

    //������� ����������� ����������, ��������� ������� 
    CentralController controller("MainController", robotList);
    std::cout << "\n���������� ������� ����� CentralController:\n";
    controller.monitorRobots();

    delete robotList;
    delete group2;
	delete group1;
    delete groupAggregate2;
	delete groupAggregate1;
	delete comm6;
	delete comm5;
	delete comm4;
	delete comm3;
	delete comm2;
	delete comm1;
    delete grBattery;
    delete grWiFi;
    delete gr4G;
	delete grNavigation;
	delete grElectricMotor;

    return 0;
}