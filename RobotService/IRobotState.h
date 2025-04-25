#pragma once
#include <iostream>

class IRobot; //��������� �����, ��� ��� ����� ���������� ����������� include

//��������� ��������� ������
class IRobotState {
protected:
	IRobot* robot; //��������� �� ������, �������� ����������� ���������
public:
	IRobotState(IRobot* robot) : robot(robot) {} //�����������, ����������� ��������� �� ������

	virtual void enter() = 0; //���� � ���������
	virtual void execute() = 0; //���������� �������� � ���������
	virtual void exit() = 0; //����� �� ���������
	virtual std::string name() const = 0; //��������� ����� ���������
};