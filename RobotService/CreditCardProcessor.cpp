#include "CreditCardProcessor.h"

void CreditCardProcessor::charge(double amount) 
{
    std::cout << "[������� ������ ����� �����] �������� " << amount << " ���. � �����\n";
}

void CreditCardProcessor::printReceipt(const std::string& details) 
{
    std::cout << "[������� ������ ����� �����] ���: " << details << "\n";
}