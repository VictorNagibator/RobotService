#pragma once
#include <iostream>

//��������� ���������
class IPaymentProcessor
{
public:
	virtual void charge(double amount) = 0; //����� ��� �������� �������
	virtual void printReceipt(const std::string& details) = 0; //����� ��� ������ ����
};