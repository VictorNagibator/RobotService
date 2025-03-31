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
    ////Исправляем кодировку консоли для корректного отображения кириллицы
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    //// --- 1. Bridge: Создаем среду и передаем ее в компоненты робота ---
    //// Создаем среду для наземного робота
    //IEnvironment* groundEnv = new GroundEnvironment();
    //// Создаем среду для воздушного робота (если понадобится)
    //IEnvironment* airEnv = new AirEnvironment();
    //// Создаем среду для водного робота (если понадобится)
    //IEnvironment* waterEnv = new WaterEnvironment();

    //// --- 2. Flyweight: Создаем фабрику сегментов карты ---
    //MapSegmentFactory* segmentFactory = new MapSegmentFactory();

    //// Создаем навигационную систему с использованием фабрики сегментов и выбранной среды (Ground)
    //// GPSNavigation принимает IEnvironment* и MapSegmentFactory*
    //INavigation* navigation = new GPSNavigation(groundEnv, segmentFactory);

    //// --- 3. Создаем другие компоненты (двигатель, связь, источник питания) ---
    //IEngine* engine = new ElectricMotor("EM-Ground-01", groundEnv);
    //ICommunication* communication = new WiFiCommunication(groundEnv);
    //IPowerSource* battery = new Battery(3000);

    //// --- 4. Создаем роботов с использованием Bridge ---
    //// Здесь мы используем SimpleRobot, который принимает все необходимые компоненты
    //// Предполагается, что SimpleRobot реализует IRobot и использует переданные компоненты
    //IRobot* robot1 = new SimpleRobot(1, "Model-A", 50.0, 70.0, "OK", "OK", engine, navigation, communication, battery);
    //// Для разнообразия создадим еще роботов с разными параметрами:
    //IRobot* robot2 = new SimpleRobot(2, "Model-B", 15.0, 95.0, "OK", "OK", engine, navigation, communication, battery);
    //IRobot* robot3 = new SimpleRobot(3, "Model-C", 80.0, 65.0, "Warning", "OK", engine, navigation, communication, battery);

    //// --- 5. Агрегат роботов (Flyweight для роботов не используется, но агрегат позволяет применять итераторы) ---
    //IAggregate<IRobot*>* robotAggregate = new MyList<IRobot*>;
    //robotAggregate->push(robot1);
    //robotAggregate->push(robot2);
    //robotAggregate->push(robot3);

    //// --- 6. Information Expert: создаем эксперта по состоянию роботов ---
    //IRobotExpert* expert = new BasicRobotExpert(); // Можно задать свои параметры, если нужно

    //// --- 7. CentralController: создаем контроллер, который использует агрегат и эксперта ---
    //CentralController* controller = new CentralController("MainController", robotAggregate, expert);

    //// --- 8. Facade: создаем RobotManager, который использует CentralController для управления роботами ---
    //RobotManager* manager = new RobotManager(controller);

    //// Демонстрируем работу системы через фасад:
    //std::cout << "=== ФАСАД: Возврат всех роботов на базу ===\n";
    //manager->returnAllRobotsToBase();

    //std::cout << "\n=== ФАСАД: Аварийная остановка всех роботов ===\n";
    //manager->emergencyStopAllRobots();

    //std::cout << "\n=== ФАСАД: Обновление маршрутов для всех роботов ===\n";
    //manager->updateRoutesForAll("Новый маршрут: ул. Ленина, 5");

    //std::cout << "\n=== ФАСАД: Отправка роботов с низким зарядом на подзарядку ===\n";
    //manager->sendLowBatteryRobotsToCharge();

    //std::cout << "\n=== Information Expert: Анализ каждого робота ===\n";
    //// Выводим рекомендации для каждого робота
    //controller->monitorRobots();  // обычный мониторинг
    //// Анализ состояния каждого робота
    //// (Методы эксперта вызываются внутри контроллера через evaluate/dispatchOrderIfSuitable, например)
    //controller->dispatchOrderIfSuitable("Улица Ленина, 5", 0.3);

    //// --- Очистка памяти ---
    //// Удаляем контроллер, агрегат, эксперта, фабрику сегментов и среды.
    //delete controller; // предположим, что он не владеет роботами (их удаляем отдельно)
    //delete robotAggregate;
    //delete expert;
    //delete segmentFactory;
    //delete groundEnv;
    //delete airEnv;
    //delete waterEnv;

    //// Удаляем роботов, если агрегат не владеет ими
    //delete robot1;
    //delete robot2;
    //delete robot3;

    //// Компоненты (двигатель, навигация, связь, источник питания) здесь не удаляются отдельно,
    //// так как они, как правило, передаются в робота и удаляются при удалении робота.

    //return 0;
}