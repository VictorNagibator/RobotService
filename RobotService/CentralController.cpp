#include "CentralController.h"
#include "ProxyIterator.h"

void CentralController::addRobot(IRobot* robot)
{
    robots->push(robot);
    std::cout << controllerName << ": ����� ��������.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
	//����� ��������� �������� ������ ������������������ �������
	bool isRobotInCollection = false;
    //�������� ������ �������� �� ��������� �������
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        if (*(it.next()) == robot) {
            isRobotInCollection = true;
            break;
        }
    }
    if (!isRobotInCollection) throw std::invalid_argument("����� �� ��������������� � �������!");

    std::cout << controllerName << ": ���������� �������� �� " << destination << "\n";
    robot->startDelivery(destination);

    //� ���������� ����� ����� �������� ������ ��������, �������� �������� �������� � �.�.

    robot->stopDelivery();
}

void CentralController::monitorRobots() const
{
    std::cout << controllerName << ": ��������� ��������� �������...\n";
    //�������� ������ �������� �� ��������� ������� ��� ��������������� ��������
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        IRobot* currentRobot = *(it.next());
        //�������� ���������� ��������� ��� ������� ������
        currentRobot->checkStatus();
    }
}

void CentralController::removeRobot(IRobot* robot)
{
	robots->remove(robot);
}

const IAggregate<IRobot*>& CentralController::getRobots() const
{
    return *robots;
}