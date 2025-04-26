#pragma once
#include "ICommand.h"

//Оплата
class ChargePaymentCommand : public ICommand {
private:
    int itemID;
public:
    ChargePaymentCommand(int itemID, IVendingMachine* vm) : itemID(itemID), ICommand(vm) {}

    std::string name() const override;
    void execute() override;
};