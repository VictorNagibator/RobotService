#pragma once
#include <iostream>

//Платежный интерфейс
class IPaymentProcessor
{
public:
	virtual void charge(double amount) = 0; //Метод для списания средств
	virtual void printReceipt(const std::string& details) = 0; //Метод для печати чека
};