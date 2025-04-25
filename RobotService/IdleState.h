#pragma once
#include "IRobotState.h"

//Состояние ожидания
class IdleState : public IRobotState {
public:
	IdleState(IRobot* robot) : IRobotState(robot) {}

    void enter() override;
    void execute() override;
    void exit() override;
    std::string name() const override;
};