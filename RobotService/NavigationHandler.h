#pragma once
#include "DiagnosticHandler.h"

//�������� ���������
class NavigationHandler : public DiagnosticHandler {
public:
	NavigationHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};