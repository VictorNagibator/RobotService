#pragma once
#include "DiagnosticHandler.h"

//�������� �����
class CommunicationHandler : public DiagnosticHandler {
private:
	const int minSignal = 5; //����������� ������� ������� ��� �����
public:
	CommunicationHandler() : DiagnosticHandler() {}

	bool handle(const IRobot& robot) override;
};