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
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== Демонстрация адаптера ===\n";
	IEngine* grElectricMotor = new ElectricMotor("EM-GR-01", 500, 75);
	INavigation* grNavigation = new YandexNavigationAdapter(1, 1); //Создаем адаптер
	ICommunication* grWiFi = new WiFiCommunication(45, 6);
	IPowerSource* grBattery = new Battery(3000);
    //Используем его для робота!
	GroundRobot robot1 = GroundRobot(1, "Model-X", grElectricMotor, grNavigation, grWiFi, grBattery);
    //Продемонстрируем работу адаптера через начало доставки
	grBattery->recharge();
	robot1.startDelivery("Улица Ленина, 5");

    std::cout << "\n=== Демонстрация декораторов для ICommunication в разных порядках ===\n";
    //Берём коммуникацию через WiFi, созданную выше
    //Порядок 1
    ICommunication* comm1 = new CommunicationEncryptorDecorator(grWiFi);
    ICommunication* comm2 = new CommunicationTimestampDecorator(comm1);
    ICommunication* comm3 = new CommunicationPrinterDecorator(comm2);

    std::cout << "\n--- Порядок 1: Вывод на экран -> Метка времени -> Шифрование ---\n";
    //Создадим ещё одного робота, но с другим средством коммуникации
    GroundRobot robot2 = GroundRobot(2, "Model-X-DECORATED", grElectricMotor, grNavigation, comm3, grBattery);
    robot2.startDelivery("Улица Молодежная, 61");

    //Порядок 2
    ICommunication* gr4G = new LTECommunication(45, 50);
    ICommunication* comm4 = new CommunicationPrinterDecorator(gr4G);
    ICommunication* comm5 = new CommunicationTimestampDecorator(comm4);
    ICommunication* comm6 = new CommunicationEncryptorDecorator(comm5);

    std::cout << "\n--- Порядок 2: Шифрование -> Метка времени -> Вывод на экран ---\n";
    //Третий робот
    GroundRobot robot3 = GroundRobot(3, "Model-X-DECORATED-v 2.0", grElectricMotor, grNavigation, comm6, grBattery);
    robot3.startDelivery("Улица Молодежная, 62");

    std::cout << "\n=== Демонстрация композита (RobotGroup) ===\n";
    //Возьмем двух ранее созданных роботов и создаем группу роботов
	IAggregate<IRobot*>* groupAggregate1 = new MyList<IRobot*>; //Создаем агрегат для группы
    RobotGroup* group1 = new RobotGroup(groupAggregate1);
    group1->addRobot(&robot2);
    group1->addRobot(&robot3);

    //Создаем вторую группу и включаем в неё ещё одного робота и первую группу 
    //(Демонстрация вложенных групп)
    IAggregate<IRobot*>* groupAggregate2 = new MyList<IRobot*>;
    RobotGroup* group2 = new RobotGroup(groupAggregate2);
    group2->addRobot(&robot1);
    group2->addRobot(group1);

    //Выполняем доставку для всей группы 
    group2->startDelivery("Склад №1");
    group2->stopDelivery();
    group2->checkStatus();

    std::cout << "\n=== Демонстрация итератора отдельно и в Центральном контроллере ===\n";
    //Создаем агрегат роботов с помощью MyList
    MyList<IRobot*>* robotList = new MyList<IRobot*>;
    robotList->push(&robot3);
    robotList->push(&robot1);
    robotList->push(&robot2);

    std::cout << "\nОбход списка роботов через итератор:\n";
    ProxyIterator<IRobot*> proxyIt(robotList->begin()); //Используем прокси, чтобы потом не чистить память
    while (proxyIt.hasNext()) {
        IRobot* robot = *(proxyIt.next());
        robot->checkStatus(); //Проверяем состояние роботов, например
    }

    //Создаем центральный контроллер, используя агрегат 
    CentralController controller("MainController", robotList);
    std::cout << "\nМониторинг роботов через CentralController:\n";
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