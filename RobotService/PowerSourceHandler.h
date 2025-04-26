#pragma once
#include "DiagnosticHandler.h"

//Проверка зарядного устройства
class PowerSourceHandler : public DiagnosticHandler {
private:
	const double minCharge = 20.0; //Минимальный заряд для работы
public:
	PowerSourceHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};