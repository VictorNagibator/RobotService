#pragma once
#include "IRobotState.h"

//Состояние зарядки
class ChargingState : public IRobotState {
public:
	ChargingState(IRobot* robot) : IRobotState(robot) {}

    void enter() override;
    void execute() override;
    void exit() override;
    std::string name() const override;
};