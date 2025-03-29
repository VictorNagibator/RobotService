#pragma once
#include "IController.h"

class RobotManager
{
private:
	IController* controller; //���������� ��� ���������� ��������

    const std::string baseLocation = "��������, 61"; //��������, ����� ����� ���� ���� �������
	const std::string chargeLocation = "��������, 62"; //����� ������ ����������
	const int lowBatteryThreshold = 20; //��������� �������� ������ ��� �������� �� ����������
public:
    RobotManager(IController* ctrl);

    //���������� ���� ������� �� ����
    void returnAllRobotsToBase();
    //��������� ��������� ���� �������
    void emergencyStopAllRobots();
    //��������� �������� ��� ���� �������
    void updateRoutesForAll(const std::string& newRoute);
    //���������� ������� � ������ ������� �� ����������
    void sendLowBatteryRobotsToCharge();
};