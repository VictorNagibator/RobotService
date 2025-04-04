#include <iostream>
#include <windows.h>
#include "ElectricMotor.h"
#include "ProxyEngine.h"
#include "GPSNavigation.h"
#include "WiFiCommunication.h"
#include "Battery.h"
#include "SimpleRobot.h"
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
#include "GroundEnvironment.h"
#include "AirEnvironment.h"
#include "WaterEnvironment.h"
#include "BasicRobotExpert.h"
#include "RobotManager.h"

int main() {
    //���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //������� ����� ��� ��������� ������ ---
    IEnvironment* groundEnv = new GroundEnvironment();
    //������� ����� ��� ���������� ������
    IEnvironment* airEnv = new AirEnvironment();

    //������� ������������� ������� � �������������� ��������� ����� (Ground)
    //����� ������ GPS �������� ������� �������� ��������� ���� (���������� �������� ��������������)
    INavigation* navigation = new GPSNavigation(groundEnv, 30, 5); 

    //������� ������ ���������� (���������, �����, �������� �������)
    IEngine* engine = new ElectricMotor("EM-Ground-01", 3000, 100, groundEnv);
    ICommunication* communication = new WiFiCommunication(100, 5, groundEnv);
    IPowerSource* battery = new Battery(3000, groundEnv);
    battery->recharge();

    //--- ����: ������� ������ � �������������� �����������, ������� �������� �� ���� ---
    IRobot* robot1 = new SimpleRobot(1, "Model-A", engine, navigation, communication, battery);

    //�������� ������� ������ ��� ������ � ������
    INavigation* navigation2 = new GPSNavigation(airEnv, 20, 5);
    IEngine* engine2 = new ElectricMotor("EM-AIR-02", 3000, 50, airEnv);
    ICommunication* communication2 = new WiFiCommunication(100, 10, airEnv);
    IPowerSource* battery2 = new Battery(5000, airEnv);
    battery2->recharge();
    IRobot* robot2 = new Drone(2, "Model-B", engine2, navigation2, communication2, battery2);

    //������� ������� � ������
    MyList<IRobot*> list;
    list.push(robot1);
    list.push(robot2);

    //������� ����������
    IController* controller = new CentralController("MainController", &list);

    //--- �������������� �������: ������� �������� �� ��������� ������� ---
    IRobotExpert* expert = new BasicRobotExpert(controller); //����� ������ ���� ���������, ���� �����

	//��������� ���������� �������, ������� � ���������� ������
	std::cout << "\n=== �������: ���������� �������, ������� � ���������� ������: "
		<< expert->countSuitableRobots() << std::endl;
	//��������� ���������� �������, ����������� � ������� ������������
	std::cout << "=== �������: ���������� �������, ����������� � ������� ������������: "
		<< expert->countRobotsInNeedOfService() << std::endl;

    //--- �����: ������� RobotManager, ������� ���������� CentralController ��� ���������� �������� ---
    RobotManager manager(controller);

    //������������� ������ ������� ����� �����:
    std::cout << "\n=== �����: ������� ���� ������� �� ���� ===\n";
    manager.returnAllRobotsToBase();
    std::cout << std::endl;

    std::cout << "=== �����: ��������� ������ ���� ������� ===\n";
    manager.emergencyStopAllRobots();
    std::cout << std::endl;

    std::cout << "=== �����: �������� ������� �� ������� � ��������� ������� ===\n";
    battery->consume(2900); //��� ������� ������ �������� ���� �������
    manager.sendLowBatteryRobotsToCharge();
    std::cout << std::endl;

    //��������� ����� ���������� �������, ������� � ���������� ������
    std::cout << "=== �������: ���������� �������, ������� � ���������� ������: "
        << expert->countSuitableRobots() << std::endl;
    std::cout << "=== �������: ���������� �������, ����������� � ������� ������������: "
        << expert->countRobotsInNeedOfService() << std::endl;

    //������� ������
    delete controller;
    delete expert;
    delete battery;
    delete battery2;
    delete engine;
    delete engine2;
    delete communication;
    delete communication2;
    delete navigation;
    delete navigation2;
    delete groundEnv;
    delete airEnv;
    delete robot1;
    delete robot2;

    return 0;
}