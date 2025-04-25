#pragma once
#include "IRobotState.h"

//��������� ��������
class DeliveringState : public IRobotState
{
private:
	std::string destination; //����� ����������
public:
    DeliveringState(IRobot* robot) : IRobotState(robot) {}

    void enter() override;
    void execute() override;
    void exit() override;
    std::string name() const override;

    void setDestination(const std::string& dest);
};