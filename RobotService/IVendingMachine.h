#pragma once
#include <iostream>
#include <unordered_map>
#include "IPaymentProcessor.h"

//Интерфейс автомата по выдаче чего-либо
class IVendingMachine {
protected:
	///Структура для хранения информации о товаре (название, цена, количество)
    struct Info { std::string label; double price; int qty; };

	std::unordered_map<int, Info> items; //ID товара -> Информация о товаре
	IPaymentProcessor* payment; //Указатель на обработчик платежей
public:
	IVendingMachine(IPaymentProcessor* paymentProcessor) : payment(paymentProcessor) {}

    //Взаимодействие с дверьми
    virtual void openDoor() = 0;
    virtual void closeDoor() = 0;
    //Выдача условного itemID
    virtual void dispense(const std::string& itemLabel);

    //Взаимодействие с товаром и оплатой
    virtual void addItem(int itemID, const std::string& label, double price, int qty);
    virtual bool hasItem(int itemID) const;
    virtual double getPrice(int itemID) const;
    virtual void deductItem(int itemID);

    virtual void chargePayment(int itemID);
    virtual void printReceipt(int itemID);
};