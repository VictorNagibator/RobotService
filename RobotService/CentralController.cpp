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
	robot->attach(this); //��������� ���������� ��� ����������� � ������
    robots->push(robot);
    std::cout << controllerName << ": ����� ��������.\n";
}

void CentralController::dispatchDelivery(
    const std::string& destination,
    IRobot* robot,
    const std::string& machineLocation,
    int itemID,
    IVendingMachine* vendingMachine
)
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

    robot->startDelivery(destination, machineLocation, itemID, vendingMachine);
    
    robot->execute(); //� ���������� ����� ����� �������� ������ ��������, �������� �������� �������� � �.�.

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
	//������� ���������� ��� ����������� � ������
	robot->detach(this);
	std::cout << controllerName << ": �������� ������ �� �������...\n";
	//������� ������ �� ���������
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

	controllerName = IController::getNameFromSnapshot(m); //��������������� ��� �����������
	robots = IController::getRobotsFromSnapshot(m); //��������������� ��������� �� ������
}