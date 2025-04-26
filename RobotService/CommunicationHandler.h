#pragma once
#include "DiagnosticHandler.h"

//Проверка связи
class CommunicationHandler : public DiagnosticHandler {
private:
	const int minSignal = 5; //Минимальный уровень сигнала для связи
public:
	CommunicationHandler() : DiagnosticHandler() {}

	bool handle(const IRobot& robot) override;
};