#include "CreditCardProcessor.h"

void CreditCardProcessor::charge(double amount) 
{
    std::cout << "[Система оплаты через карту] Списываю " << amount << " руб. с карты\n";
}

void CreditCardProcessor::printReceipt(const std::string& details) 
{
    std::cout << "[Система оплаты через карту] Чек: " << details << "\n";
}