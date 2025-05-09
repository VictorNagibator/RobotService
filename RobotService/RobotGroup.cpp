#include "RobotGroup.h"
#include "MyList.h"
#include "ProxyIterator.h"

void RobotGroup::addRobot(IRobot* robot)
{
	robots->push(robot);
}

void RobotGroup::removeRobot(IRobot* robot)
{
	robots->remove(robot);
}

void RobotGroup::startDelivery(const std::string& destination, const std::string& machineLocation,
	int itemID,
	IVendingMachine* vendingMachine)
{
	//���������� ����� ���� ������� � ������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->startDelivery(destination, machineLocation, itemID, vendingMachine);
	}
}

void RobotGroup::startCharging()
{
	//���������� ����� ���� ������� � ������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->startCharging();
	}
}

void RobotGroup::runDiagnostics()
{
	//���������� ����� ���� ������� � ������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->runDiagnostics();
	}
}

void RobotGroup::wait()
{
	//���������� ����� ���� ������� � ������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->wait();
	}
}

void RobotGroup::checkStatus()
{
	//����������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->checkStatus();
	}
}

void RobotGroup::moveTo(const std::string& destination)
{
	//����������
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->moveTo(destination);
	}
}

IRobot* RobotGroup::clone() const
{
	//������� ����� ������ RobotGroup � �������� � ���� ������� �� ������� ������
	RobotGroup* newGroup = new RobotGroup(new MyList<IRobot*>());
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		newGroup->addRobot((*it.next())->clone());
	}
	return newGroup;
}