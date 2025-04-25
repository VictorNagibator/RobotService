#include "RobotManager.h"
#include "ProxyIterator.h"

RobotManager::RobotManager(IController* ctrl)
{
    controller = ctrl;
}

void RobotManager::returnAllRobotsToBase()
{
    std::cout << "[�������� ��������] ���������� ���� ������� �� ����: " << baseLocation << "\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->wait();
		robot->moveTo(baseLocation);
        std::cout << "����� ��������� �� ����.\n";
    }
}

void RobotManager::emergencyStopAllRobots()
{
    std::cout << "[�������� ��������] ��������� ��������� ���� �������.\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->wait();
    }
    std::cout << "��� ������ �����������.\n";
}

void RobotManager::updateRoutesForAll(const std::string& newRoute) 
{
    std::cout << "[�������� ��������] ���������� ��������� ��� ���� �������: " << newRoute << "\n";
    auto& collection = controller->getRobots();

    ProxyIterator<IRobot*> it(collection.begin());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->startDelivery(newRoute);
    }
}

void RobotManager::sendLowBatteryRobotsToCharge(double minBatteryLevel)
{
    std::cout << "[�������� ��������] �������� ������� � ������ ������� �� ����������.\n";
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