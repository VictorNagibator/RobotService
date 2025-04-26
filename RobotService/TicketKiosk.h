#pragma once
#include "IVendingMachine.h"

//������� �� ������� �������
class TicketKiosk : public IVendingMachine {
public:
	TicketKiosk(IPaymentProcessor* processor) : IVendingMachine(processor) {}

    void openDoor() override;
    void dispense(const std::string& itemLabel) override;
    void closeDoor() override;
};