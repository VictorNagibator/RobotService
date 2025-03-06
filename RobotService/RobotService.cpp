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

int main() {
	//���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== ������������ ������� ���������� ������ ===\n";

    //������� ���������� ��� ��������� ������
    //1. ���������: ���������������� ������������� � EngineProxy
    IEngine* grElectricMotor = new ElectricMotor("EM-GR-01", 500, 75);
    IEngine* grEngineProxy = new ProxyEngine(grElectricMotor);
    //2. ������������� �������: GPS
    INavigation* grNavigation = new GPSNavigation(3.5, 8);
    //3. �������� �����: WiFi
    ICommunication* grWiFi = new WiFiCommunication(45, 6);
    //4. �������� �������: �������
    IPowerSource* grBattery = new Battery(3000);

    //������� ��������� ������ � ������ ������������
    GroundRobot groundRobot(1, "Model-X", grEngineProxy,
        grNavigation, grWiFi, grBattery);

    //������� ���������� ��� ��������� ������
    //1. ���������: ����������� ��������
    IEngine* drCombustionEngine = new CombustionEngine("CE-DR-01", 1000, 90);
    //2. ������������� �������: ������ ����� ������
    INavigation* drVisionNav = new VisionNavigation("1080p", 30);
    //3. �������� �����: 4G
    ICommunication* drFourG = new LTECommunication(30, 50);
    //4. �������� �������: ��������� �������
    IPowerSource* drFuelCell = new FuelCell(FuelType::A95, 50);

    //������� ��������� ������ � ��������� ������������.
    Drone drone(2, "Model-D", drCombustionEngine,
        drVisionNav, drFourG, drFuelCell);

    //������� ����������� ���������� � ������������ �������
    CentralController controller("MainController");
    controller.addRobot(&groundRobot);
    controller.addRobot(&drone);

    //������������ �������������:
    //������ ����� ��� ������� �������� ���������� ����� ������ ���������, ������������� � ���������������� ��������.
    std::cout << "\n=== ���������� ��������� ������� ===\n";
    controller.monitorRobots();

    std::cout << "\n=== ������������� ������� ===\n";
    //��������� ��������: ��� ��������� ������ �� ������� ������
    controller.dispatchDelivery(&groundRobot, "��-� ������, 10");
    std::cout << "\n";
    //������ �������
	grBattery->recharge();
    controller.dispatchDelivery(&groundRobot, "��-� ������, 10");
    std::cout << "\n";
	//����� ������� ����������� ��������� ��������� ������ �� ���������� ������� ��� �������
    grEngineProxy->setTemperature(100);
    //������ ��������� ��������� �� ����� �����������
	controller.dispatchDelivery(&groundRobot, "��. ��������, 15");
    std::cout << "\n";
	
	//��� ����� ��� ������� �� ��������� ������ ��������
    controller.dispatchDelivery(&drone, "�� ����������, 5");
	std::cout << "\n";
	//������ ������� � �� ���������
    drFuelCell->recharge();
	controller.dispatchDelivery(&drone, "�� ����������, 6");

    std::cout << "\n";
    controller.monitorRobots();
    std::cout << "=== ���������� ������ ������� ===\n";
    return 0;
}