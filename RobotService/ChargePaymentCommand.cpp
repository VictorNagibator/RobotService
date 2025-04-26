#include "ChargePaymentCommand.h"
#include <string>

std::string ChargePaymentCommand::name() const 
{ 
    return "Оплата товара (" + std::to_string(itemID) + ")";
}

void ChargePaymentCommand::execute()
{
    std::cout << "Списание оплаты за товар " << itemID << "\n";
    vendingMachine->chargePayment(itemID);
}