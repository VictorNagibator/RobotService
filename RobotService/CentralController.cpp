#include "CentralController.h"
#include "ProxyIterator.h"

//���������� ����������� ����������
CentralController* CentralController::self = nullptr;

CentralController* CentralController::getInstance(const std::string& name, IAggregate<IRobot*>* collection) 
{
	//���������, ���������� �� ��� ��������� �����������
    if (!self) {
		self = new CentralController(name, collection); //���� ���, ������� �����
    }
	return self; //���������� ������������ ���������
}

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

    robot->wait();
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

ControllerSnapshot* CentralController::saveState()
{
	std::cout << controllerName << ": ���������� ��������� �����������...\n";

	//������� ����� ��������� �������
	MyList<IRobot*>* robotsCopy = new MyList<IRobot*>();

    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        IRobot* currentRobot = *(it.next());
		robotsCopy->push(currentRobot->clone()); //�������� ������ ����� ���������
    }

	return IController::makeSnapshot(controllerName, robotsCopy); //������� ������ ��������� �����������
}

void CentralController::restoreState(ControllerSnapshot* m)
{
	std::cout << controllerName << ": �������������� ��������� �����������...\n";
	//������� ������ ��������� �������
	delete robots;

	controllerName = IController::getName(m); //��������������� ��� �����������
	robots = IController::getRobots(m); //��������������� ��������� �� ������
}