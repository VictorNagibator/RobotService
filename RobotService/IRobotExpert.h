#pragma once
#include "IController.h"

//��������� ��������������� �������� �� ��������� �������
class IRobotExpert {
protected:
	IController* controller; //����������, � ������� �������� �������
public:
	IRobotExpert(IController* controller) : controller(controller) {} //����������� � ��������� �����������

    //���������� ���������� �������, ������� � ���������� ������
    virtual int countSuitableRobots() const = 0;

	//���������� ���������� �������, ����������� � ������� ������������
	virtual int countRobotsInNeedOfService() const = 0;
};