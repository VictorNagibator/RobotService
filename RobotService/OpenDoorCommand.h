#pragma once
#include "ICommand.h"

//Открыть дверцу
class OpenDoorCommand : public ICommand {
public:
	OpenDoorCommand(IVendingMachine* vm) : ICommand(vm) {}

    std::string name() const override;
    void execute() override;
};