#pragma once
#include "IRobot.h"
#include "MyList.h"

//��������� ��������������� �������� �� ��������� �������
class IRobotExpert {
public:
    //���������� true, ���� ����� ����� � ���������� ������
    virtual bool isRobotSuitable(IRobot* robot) const = 0;

    //���������� ������ �������, ������� � ���������� ������
    virtual MyList<IRobot*> filterSuitableRobots(const IAggregate<IRobot*>& allRobots) const = 0;
};