#pragma once
#include "IRobot.h"
#include "IAggregate.h"
#include "ControllerSnapshot.h"

//��������� ������������ �����������
class IController {
protected:
    std::string controllerName;

    //��������������� ������, ����� ����� ������ � ����� friend ������ �����������
    ControllerSnapshot* makeSnapshot(std::string name, IAggregate<IRobot*>* robots) const;
    std::string getName(ControllerSnapshot* snap) const;
	IAggregate<IRobot*>* getRobots(ControllerSnapshot* snap) const;
public:
	IController(const std::string& name) : controllerName(name) {};

	//������ ��� ���������� � �������������� ��������� �����������
    virtual ControllerSnapshot* saveState() = 0;
    virtual void restoreState(ControllerSnapshot* m) = 0;

    virtual void addRobot(IRobot* robot) = 0;
	virtual void removeRobot(IRobot* robot) = 0;
    virtual void dispatchDelivery(IRobot* robot, const std::string& destination) = 0;
    virtual void monitorRobots() const = 0;

    virtual const IAggregate<IRobot*>& getRobots() const = 0;
};