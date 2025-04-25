#pragma once
#include "IRobotState.h"

//Состояние доставки
class DeliveringState : public IRobotState
{
private:
	std::string destination; //Пункт назначения
public:
    DeliveringState(IRobot* robot) : IRobotState(robot) {}

    void enter() override;
    void execute() override;
    void exit() override;
    std::string name() const override;

    void setDestination(const std::string& dest);
};