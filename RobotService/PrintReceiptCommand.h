#pragma once
#include "ICommand.h"

//Печать чека
class PrintReceiptCommand : public ICommand {
    int itemID;
public:
    PrintReceiptCommand(int itemID, IVendingMachine* vm) : itemID(itemID), ICommand(vm) {}
    std::string name() const override;
    void execute() override;
};
