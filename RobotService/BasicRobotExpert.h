#pragma once
#include "IRobotExpert.h"
#include "Iterator.h"

class BasicRobotExpert : public IRobotExpert {
private:
    double maxSafeTemperatureForEngine = 90.0; //������������ ����� ����������� ���������
	double minBatteryLevel = 20.0; //����������� ����� �������

	//������������ ����������� ��� �������� (90% �� ������������; �� �� �����, ����� ����� �� ����� �������� ��������)
	const double maxTemperatureForDelivery = maxSafeTemperatureForEngine * 0.9; 
	//���������� ��� ������ �������
	const double minBatteryLevelForDelivery = minBatteryLevel * 1.1;
public:
	BasicRobotExpert(IController* ctrl) : IRobotExpert(ctrl) {} //����� �������� �������� �� ���������
	BasicRobotExpert(IController* ctrl, double maxSafeTemperatureForEngine, double minBatteryLevel); //� ����� ������ ����

	//���������� ���������� �������, ������� � ���������� ������
	int countSuitableRobots() const override;

	//���������� ���������� �������, ����������� � ������� ������������
	int countRobotsInNeedOfService() const override;
};