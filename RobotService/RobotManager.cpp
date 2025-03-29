#include "RobotManager.h"
#include "ProxyIterator.h"

RobotManager::RobotManager(IController* ctrl)
{
    controller = ctrl;
}

void RobotManager::returnAllRobotsToBase()
{
    std::cout << "[������� ��������] ���������� ���� ������� �� ����: " << baseLocation << "\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->stopDelivery();
		robot->moveTo(baseLocation);
        std::cout << "����� ��������� �� ����.\n";
    }
}

void RobotManager::emergencyStopAllRobots()
{
    std::cout << "[������� ��������] ��������� ��������� ���� �������.\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->stopDelivery();
    }
    std::cout << "��� ������ �����������.\n";
}

void RobotManager::updateRoutesForAll(const std::string& newRoute) 
{
    std::cout << "[������� ��������] ���������� ��������� ��� ���� �������: " << newRoute << "\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        robot->startDelivery(newRoute);
    }
}

void RobotManager::sendLowBatteryRobotsToCharge()
{
    std::cout << "[������� ��������] �������� ������� � ������ ������� �� ����������.\n";
    ProxyIterator<IRobot*> it(controller->getRobots());
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        if (robot->getPowerSource().getCharge() < lowBatteryThreshold) {
			robot->moveTo(chargeLocation);
        }
    }
}