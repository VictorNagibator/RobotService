#pragma once
#include "DiagnosticHandler.h"

//Проверка двигателя
class EngineHandler : public DiagnosticHandler {
public:
    EngineHandler() : DiagnosticHandler() {}

    bool handle(const IRobot& robot) override;
};