#pragma once
#include "ICommand.h"

//�������� �������
class CheckStockCommand : public ICommand {
private:
    int itemID;
public:
    CheckStockCommand(int itemID, IVendingMachine* vm) : itemID(itemID), ICommand(vm) {}

    std::string name() const override;
    void execute() override;
};