#include "RobotManager.h"
#include "ProxyIterator.h"

RobotManager::RobotManager(IController* ctrl)
{
    controller = ctrl;
}

void RobotManager::returnAllRobotsToBase()
{
    std::cout << "[Менеджер роботами] Возвращаем всех роботов на базу: " << baseLocation << "\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->wait();
		robot->moveTo(baseLocation);
        std::cout << "Робот переведен на базу.\n";
    }
}

void RobotManager::emergencyStopAllRobots()
{
    std::cout << "[Менеджер роботами] Аварийная остановка всех роботов.\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->wait();
    }
    std::cout << "Все роботы остановлены.\n";
}

void RobotManager::updateRoutesForAll(const std::string& newRoute) 
{
    std::cout << "[Менеджер роботами] Обновление маршрутов для всех роботов: " << newRoute << "\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->startDelivery(newRoute);
    }
}

void RobotManager::sendLowBatteryRobotsToCharge(double minBatteryLevel)
{
    std::cout << "[Менеджер роботами] Отправка роботов с низким зарядом на подзарядку.\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());

		double batteryLevel = robot->getPowerSource()->getCharge();

        if (batteryLevel < minBatteryLevel) {
            robot->startCharging();
			robot->moveTo(chargeLocation);
            robot->execute();
        }
    }
}