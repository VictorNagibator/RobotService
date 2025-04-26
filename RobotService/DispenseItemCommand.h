#pragma once
#include "ICommand.h"

//������ �����
class DispenseItemCommand : public ICommand {
    int itemID;
public:
    DispenseItemCommand(int itemID, IVendingMachine* vm) : itemID(itemID), ICommand(vm) {}
    std::string name() const override;
    void execute() override;
};