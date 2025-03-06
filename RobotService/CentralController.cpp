#include "CentralController.h"

void CentralController::addRobot(IRobot* robot)
{
    robots.push_back(robot);
    std::cout << controllerName << ": ����� ��������.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
    //����� �������� ������ � ��������, ������� ���� � �������
    if (std::find(robots.begin(), robots.end(), robot) == robots.end()) 
		throw std::invalid_argument("����� �� ��������������� � �������!");

    std::cout << controllerName << ": ���������� �������� �� " << destination << "\n";
    robot->startDelivery(destination);

    //� ���������� ����� ����� �������� ������ ��������, �������� �������� �������� � �.�.

    robot->stopDelivery();
}

void CentralController::monitorRobots()
{
    std::cout << controllerName << ": ��������� ��������� �������...\n";
    for (auto r : robots) {
        r->checkStatus();
    }
}