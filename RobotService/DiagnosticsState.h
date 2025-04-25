#pragma once
#include "IRobotState.h"

//��������� �����������
class DiagnosticsState : public IRobotState {
public:
	DiagnosticsState(IRobot* robot) : IRobotState(robot) {}

    void enter() override;
    void execute() override;
    void exit() override;
    std::string name() const override;
};