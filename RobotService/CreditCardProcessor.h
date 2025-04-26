#pragma once
#include "IPaymentProcessor.h"

//���������� ���������� - ��������� �������� ����� ���������� �����
class CreditCardProcessor : public IPaymentProcessor {
public:
    void charge(double amount) override;
    void printReceipt(const std::string& details) override;
};