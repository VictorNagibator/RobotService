#include "ChargePaymentCommand.h"
#include <string>

std::string ChargePaymentCommand::name() const 
{ 
    return "������ ������ (" + std::to_string(itemID) + ")";
}

void ChargePaymentCommand::execute()
{
    std::cout << "�������� ������ �� ����� " << itemID << "\n";
    vendingMachine->chargePayment(itemID);
}