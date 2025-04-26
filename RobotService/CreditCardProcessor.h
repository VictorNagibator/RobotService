#pragma once
#include "IPaymentProcessor.h"

//Конкретная реализация - обработка платежей через банковскую карту
class CreditCardProcessor : public IPaymentProcessor {
public:
    void charge(double amount) override;
    void printReceipt(const std::string& details) override;
};