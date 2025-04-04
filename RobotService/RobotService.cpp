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
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Создаем среду для наземного робота ---
    IEnvironment* groundEnv = new GroundEnvironment();
    //Создаем среду для воздушного робота
    IEnvironment* airEnv = new AirEnvironment();

    //Создаем навигационную систему с использованием выбранной среды (Ground)
    //Также внутри GPS хранится фабрика создания сегментов улиц (реализация паттерна Приспособленец)
    INavigation* navigation = new GPSNavigation(groundEnv, 30, 5); 

    //Создаем другие компоненты (двигатель, связь, источник питания)
    IEngine* engine = new ElectricMotor("EM-Ground-01", 3000, 100, groundEnv);
    ICommunication* communication = new WiFiCommunication(100, 5, groundEnv);
    IPowerSource* battery = new Battery(3000, groundEnv);
    battery->recharge();

    //--- Мост: создаем робота с использованием компонентов, которые работают на суше ---
    IRobot* robot1 = new SimpleRobot(1, "Model-A", engine, navigation, communication, battery);

    //Создадим другого робота для полётов в городе
    INavigation* navigation2 = new GPSNavigation(airEnv, 20, 5);
    IEngine* engine2 = new ElectricMotor("EM-AIR-02", 3000, 50, airEnv);
    ICommunication* communication2 = new WiFiCommunication(100, 10, airEnv);
    IPowerSource* battery2 = new Battery(5000, airEnv);
    battery2->recharge();
    IRobot* robot2 = new Drone(2, "Model-B", engine2, navigation2, communication2, battery2);

    //Добавим роботов в список
    MyList<IRobot*> list;
    list.push(robot1);
    list.push(robot2);

    //Создаем контроллер
    IController* controller = new CentralController("MainController", &list);

    //--- Информационный эксперт: создаем эксперта по состоянию роботов ---
    IRobotExpert* expert = new BasicRobotExpert(controller); //Можно задать свои параметры, если нужно

	//Проверяем количество роботов, готовых к выполнению заказа
	std::cout << "\n=== ЭКСПЕРТ: Количество роботов, готовых к выполнению заказа: "
		<< expert->countSuitableRobots() << std::endl;
	//Проверяем количество роботов, нуждающихся в срочном обслуживании
	std::cout << "=== ЭКСПЕРТ: Количество роботов, нуждающихся в срочном обслуживании: "
		<< expert->countRobotsInNeedOfService() << std::endl;

    //--- Фасад: создаем RobotManager, который использует CentralController для управления роботами ---
    RobotManager manager(controller);

    //Демонстрируем работу системы через фасад:
    std::cout << "\n=== ФАСАД: Возврат всех роботов на базу ===\n";
    manager.returnAllRobotsToBase();
    std::cout << std::endl;

    std::cout << "=== ФАСАД: Остановка работы всех роботов ===\n";
    manager.emergencyStopAllRobots();
    std::cout << std::endl;

    std::cout << "=== ФАСАД: Отправка роботов на зарядку с маленьким зарядом ===\n";
    battery->consume(2900); //Для примера сильно разряжаю одну батарею
    manager.sendLowBatteryRobotsToCharge();
    std::cout << std::endl;

    //Проверяем вновь количество роботов, готовых к выполнению заказа
    std::cout << "=== ЭКСПЕРТ: Количество роботов, готовых к выполнению заказа: "
        << expert->countSuitableRobots() << std::endl;
    std::cout << "=== ЭКСПЕРТ: Количество роботов, нуждающихся в срочном обслуживании: "
        << expert->countRobotsInNeedOfService() << std::endl;

    //Очистим память
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