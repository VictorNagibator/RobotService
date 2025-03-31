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
        robot->stopDelivery();
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
        robot->stopDelivery();
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
        if (robot->getPowerSource().getCharge() < minBatteryLevel) {
			robot->moveTo(chargeLocation);
        }
    }
}

int RobotManager::getSuitableRobotsCount() const
{
    auto& expert = controller->getRobotExpert();
    auto& collection = controller->getRobots();
    //� ������� �������� �������� �������, ��������� ���������� ������
    auto suitableCollection = expert.filterSuitableRobots(controller->getRobots());

    int count = 0;
    ProxyIterator<IRobot*> it(suitableCollection.begin());
    while (it.hasNext()) {
        count++; //������� ���������� ������� �������
    }
    return count;
}