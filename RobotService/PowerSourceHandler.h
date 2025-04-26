#pragma once
#include "DiagnosticHandler.h"

//�������� ��������� ����������
class PowerSourceHandler : public DiagnosticHandler {
private:
	const double minCharge = 20.0; //����������� ����� ��� ������
public:
	PowerSourceHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};