#pragma once
#include "IVendingMachine.h"

//��������� ������� ��� �������������� � ���������
class ICommand {
protected:
	IVendingMachine* vendingMachine; //��������� �� �������
public:
	ICommand(IVendingMachine* vendingMachine) : vendingMachine(vendingMachine) {}

	virtual void execute() = 0; //���������� �������
	virtual std::string name() const = 0; //��� �������
};