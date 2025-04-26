#pragma once
#include "ICommand.h"

//Закрыть дверцу
class CloseDoorCommand : public ICommand {
public:
    CloseDoorCommand(IVendingMachine* vm) : ICommand(vm) {}

    std::string name() const override;
    void execute() override;
};