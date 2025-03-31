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
#include "GroundEnvironment.h"
#include "AirEnvironment.h"
#include "WaterEnvironment.h"

int main() {
    ////���������� ��������� ������� ��� ����������� ����������� ���������
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    //// --- 1. Bridge: ������� ����� � �������� �� � ���������� ������ ---
    //// ������� ����� ��� ��������� ������
    //IEnvironment* groundEnv = new GroundEnvironment();
    //// ������� ����� ��� ���������� ������ (���� �����������)
    //IEnvironment* airEnv = new AirEnvironment();
    //// ������� ����� ��� ������� ������ (���� �����������)
    //IEnvironment* waterEnv = new WaterEnvironment();

    //// --- 2. Flyweight: ������� ������� ��������� ����� ---
    //MapSegmentFactory* segmentFactory = new MapSegmentFactory();

    //// ������� ������������� ������� � �������������� ������� ��������� � ��������� ����� (Ground)
    //// GPSNavigation ��������� IEnvironment* � MapSegmentFactory*
    //INavigation* navigation = new GPSNavigation(groundEnv, segmentFactory);

    //// --- 3. ������� ������ ���������� (���������, �����, �������� �������) ---
    //IEngine* engine = new ElectricMotor("EM-Ground-01", groundEnv);
    //ICommunication* communication = new WiFiCommunication(groundEnv);
    //IPowerSource* battery = new Battery(3000);

    //// --- 4. ������� ������� � �������������� Bridge ---
    //// ����� �� ���������� SimpleRobot, ������� ��������� ��� ����������� ����������
    //// ��������������, ��� SimpleRobot ��������� IRobot � ���������� ���������� ����������
    //IRobot* robot1 = new SimpleRobot(1, "Model-A", 50.0, 70.0, "OK", "OK", engine, navigation, communication, battery);
    //// ��� ������������ �������� ��� ������� � ������� �����������:
    //IRobot* robot2 = new SimpleRobot(2, "Model-B", 15.0, 95.0, "OK", "OK", engine, navigation, communication, battery);
    //IRobot* robot3 = new SimpleRobot(3, "Model-C", 80.0, 65.0, "Warning", "OK", engine, navigation, communication, battery);

    //// --- 5. ������� ������� (Flyweight ��� ������� �� ������������, �� ������� ��������� ��������� ���������) ---
    //IAggregate<IRobot*>* robotAggregate = new MyList<IRobot*>;
    //robotAggregate->push(robot1);
    //robotAggregate->push(robot2);
    //robotAggregate->push(robot3);

    //// --- 6. Information Expert: ������� �������� �� ��������� ������� ---
    //IRobotExpert* expert = new BasicRobotExpert(); // ����� ������ ���� ���������, ���� �����

    //// --- 7. CentralController: ������� ����������, ������� ���������� ������� � �������� ---
    //CentralController* controller = new CentralController("MainController", robotAggregate, expert);

    //// --- 8. Facade: ������� RobotManager, ������� ���������� CentralController ��� ���������� �������� ---
    //RobotManager* manager = new RobotManager(controller);

    //// ������������� ������ ������� ����� �����:
    //std::cout << "=== �����: ������� ���� ������� �� ���� ===\n";
    //manager->returnAllRobotsToBase();

    //std::cout << "\n=== �����: ��������� ��������� ���� ������� ===\n";
    //manager->emergencyStopAllRobots();

    //std::cout << "\n=== �����: ���������� ��������� ��� ���� ������� ===\n";
    //manager->updateRoutesForAll("����� �������: ��. ������, 5");

    //std::cout << "\n=== �����: �������� ������� � ������ ������� �� ���������� ===\n";
    //manager->sendLowBatteryRobotsToCharge();

    //std::cout << "\n=== Information Expert: ������ ������� ������ ===\n";
    //// ������� ������������ ��� ������� ������
    //controller->monitorRobots();  // ������� ����������
    //// ������ ��������� ������� ������
    //// (������ �������� ���������� ������ ����������� ����� evaluate/dispatchOrderIfSuitable, ��������)
    //controller->dispatchOrderIfSuitable("����� ������, 5", 0.3);

    //// --- ������� ������ ---
    //// ������� ����������, �������, ��������, ������� ��������� � �����.
    //delete controller; // �����������, ��� �� �� ������� �������� (�� ������� ��������)
    //delete robotAggregate;
    //delete expert;
    //delete segmentFactory;
    //delete groundEnv;
    //delete airEnv;
    //delete waterEnv;

    //// ������� �������, ���� ������� �� ������� ���
    //delete robot1;
    //delete robot2;
    //delete robot3;

    //// ���������� (���������, ���������, �����, �������� �������) ����� �� ��������� ��������,
    //// ��� ��� ���, ��� �������, ���������� � ������ � ��������� ��� �������� ������.

    //return 0;
}