#pragma once
#include "DiagnosticHandler.h"

//�������� ���������
class EngineHandler : public DiagnosticHandler {
public:
    EngineHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};