#pragma once
#include "IVendingMachine.h"

//Автомат по выдаче посылок
class ParcelLocker : public IVendingMachine {
public:
	ParcelLocker(IPaymentProcessor* processor) : IVendingMachine(processor) {}

    void openDoor() override;
    void dispense(const std::string& itemLabel) override;
    void closeDoor() override;
};