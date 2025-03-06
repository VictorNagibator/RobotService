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
	//Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== Конфигурация системы курьерской службы ===\n";

    //Создаем компоненты для наземного робота
    //1. Двигатель: Электродвигатель оборачивается в EngineProxy
    IEngine* grElectricMotor = new ElectricMotor("EM-GR-01", 500, 75);
    IEngine* grEngineProxy = new ProxyEngine(grElectricMotor);
    //2. Навигационная система: GPS
    INavigation* grNavigation = new GPSNavigation(3.5, 8);
    //3. Средство связи: WiFi
    ICommunication* grWiFi = new WiFiCommunication(45, 6);
    //4. Источник питания: батарея
    IPowerSource* grBattery = new Battery(3000);

    //Создаем наземного робота с такими компонентами
    GroundRobot groundRobot(1, "Model-X", grEngineProxy,
        grNavigation, grWiFi, grBattery);

    //Создаем компоненты для летающего робота
    //1. Двигатель: внутреннего сгорания
    IEngine* drCombustionEngine = new CombustionEngine("CE-DR-01", 1000, 90);
    //2. Навигационная система: зрение через камеры
    INavigation* drVisionNav = new VisionNavigation("1080p", 30);
    //3. Средство связи: 4G
    ICommunication* drFourG = new LTECommunication(30, 50);
    //4. Источник питания: топливный элемент
    IPowerSource* drFuelCell = new FuelCell(FuelType::A95, 50);

    //Создаем летающего робота с заданными компонентами.
    Drone drone(2, "Model-D", drCombustionEngine,
        drVisionNav, drFourG, drFuelCell);

    //Создаем центральный контроллер и регистрируем роботов
    CentralController controller("MainController");
    controller.addRobot(&groundRobot);
    controller.addRobot(&drone);

    //Демонстрация делегирования:
    //Каждый робот при запуске доставки делегирует вызов своему двигателю, навигационной и коммуникационной системам.
    std::cout << "\n=== Мониторинг состояния роботов ===\n";
    controller.monitorRobots();

    std::cout << "\n=== Распределение заданий ===\n";
    //Запускаем доставку: для наземного робота не хватает заряда
    controller.dispatchDelivery(&groundRobot, "пр-т Ленина, 10");
    std::cout << "\n";
    //Теперь зарядим
	grBattery->recharge();
    controller.dispatchDelivery(&groundRobot, "пр-т Ленина, 10");
    std::cout << "\n";
	//Затем обновим температуру двигателя наземного робота до достаточно высокой для запуска
    grEngineProxy->setTemperature(100);
    //Теперь двигатель корректно не будет запускаться
	controller.dispatchDelivery(&groundRobot, "ул. Анатолия, 15");
    std::cout << "\n";
	
	//Для дрона без топлива не получится начать доставку
    controller.dispatchDelivery(&drone, "ул Молодежная, 5");
	std::cout << "\n";
	//Теперь зарядим и всё получится
    drFuelCell->recharge();
	controller.dispatchDelivery(&drone, "ул Молодежная, 6");

    std::cout << "\n";
    controller.monitorRobots();
    std::cout << "=== Завершение работы системы ===\n";
    return 0;
}