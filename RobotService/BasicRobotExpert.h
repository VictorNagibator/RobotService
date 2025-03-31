#pragma once
#include "IRobotExpert.h"
#include "Iterator.h"

class BasicRobotExpert : public IRobotExpert {
private:
    double maxSafeTemperatureForEngine = 90.0; //������������ ����� ����������� ���������
	double minBatteryLevel = 20.0; //����������� ����� �������
public:
	BasicRobotExpert() {} //����� �������� �������� �� ���������
    BasicRobotExpert(double maxSafeTemperatureForEngine, double minBatteryLevel); //� ����� ������ ����

    //���� �������� ���������� ������ � ������
    bool isRobotSuitable(IRobot* robot) const override;

	//��������� ������� � �������� � ���������� ���, ��� ����� � ������������� ��������
    MyList<IRobot*> filterSuitableRobots(const IAggregate<IRobot*>& allRobots) const override;
};