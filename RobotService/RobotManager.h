#pragma once
#include "IController.h"

class RobotManager
{
private:
	IController* controller; //���������� ��� ���������� ��������

    const std::string baseLocation = "��������, 61"; //��������, ����� ����� ���� ���� �������
	const std::string chargeLocation = "��������, 62"; //����� ������ ����������
public:
    RobotManager(IController* ctrl);

    //���������� ���� ������� �� ����
    void returnAllRobotsToBase();
    //��������� ��������� ���� �������
    void emergencyStopAllRobots();
    //��������� �������� ��� ���� �������
    void updateRoutesForAll(const std::string& newRoute);
    //���������� ������� � ������ ������� �� ����������
    void sendLowBatteryRobotsToCharge(double minBatteryLevel = 20.0);

    //����������� ������, ������� ������� �������� ���������� ������
	int getSuitableRobotsCount() const;
};