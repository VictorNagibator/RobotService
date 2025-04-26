#pragma once
#include <iostream>
#include <unordered_map>
#include "IPaymentProcessor.h"

//��������� �������� �� ������ ����-����
class IVendingMachine {
protected:
	///��������� ��� �������� ���������� � ������ (��������, ����, ����������)
    struct Info { std::string label; double price; int qty; };

	std::unordered_map<int, Info> items; //ID ������ -> ���������� � ������
	IPaymentProcessor* payment; //��������� �� ���������� ��������
public:
	IVendingMachine(IPaymentProcessor* paymentProcessor) : payment(paymentProcessor) {}

    //�������������� � �������
    virtual void openDoor() = 0;
    virtual void closeDoor() = 0;
    //������ ��������� itemID
    virtual void dispense(const std::string& itemLabel);

    //�������������� � ������� � �������
    virtual void addItem(int itemID, const std::string& label, double price, int qty);
    virtual bool hasItem(int itemID) const;
    virtual double getPrice(int itemID) const;
    virtual void deductItem(int itemID);

    virtual void chargePayment(int itemID);
    virtual void printReceipt(int itemID);
};