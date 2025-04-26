#pragma once
#include "DiagnosticHandler.h"

//Проверка навигации
class NavigationHandler : public DiagnosticHandler {
public:
	NavigationHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};