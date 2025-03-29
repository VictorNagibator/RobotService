#include "RobotManager.h"
#include "ProxyIterator.h"

RobotManager::RobotManager(IController* ctrl)
{
    controller = ctrl;
}

void RobotManager::returnAllRobotsToBase()
{
    std::cout << "[Менджер роботами] Возвращаем всех роботов на базу: " << baseLocation << "\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->stopDelivery();
		robot->moveTo(baseLocation);
        std::cout << "Робот переведен на базу.\n";
    }
}

void RobotManager::emergencyStopAllRobots()
{
    std::cout << "[Менджер роботами] Аварийная остановка всех роботов.\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->stopDelivery();
    }
    std::cout << "Все роботы остановлены.\n";
}

void RobotManager::updateRoutesForAll(const std::string& newRoute) 
{
    std::cout << "[Менджер роботами] Обновление маршрутов для всех роботов: " << newRoute << "\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->startDelivery(newRoute);
    }
}

void RobotManager::sendLowBatteryRobotsToCharge()
{
    std::cout << "[Менджер роботами] Отправка роботов с низким зарядом на подзарядку.\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        if (robot->getPowerSource().getCharge() < lowBatteryThreshold) {
			robot->moveTo(chargeLocation);
        }
    }
}