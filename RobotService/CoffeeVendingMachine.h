#pragma once
#include "IVendingMachine.h"

//�������� �������
class CoffeeVendingMachine : public IVendingMachine {
public:
	CoffeeVendingMachine(IPaymentProcessor* processor) : IVendingMachine(processor) {}

    void openDoor() override;
    void dispense(const std::string& itemLabel) override;
    void closeDoor() override;
};