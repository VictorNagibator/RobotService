#include "IVendingMachine.h"
#include <string>

void IVendingMachine::addItem(int itemID, const std::string& label, double price, int qty)
{
    items[itemID] = { label, price, qty };
}

bool IVendingMachine::hasItem(int itemID) const
{
    auto it = items.find(itemID);
	return it != items.end() && it->second.qty > 0; //Проверяем, что есть в наличии
}

double IVendingMachine::getPrice(int itemID) const
{
    auto it = items.find(itemID);
    if (it == items.end()) throw std::runtime_error("Нет такого товара на складе!");
    return it->second.price;
}

void IVendingMachine::deductItem(int itemID)
{
    auto& info = items.at(itemID);
    if (info.qty <= 0) throw std::runtime_error("Нет такого товара на складе!");
    --info.qty;
}

void IVendingMachine::chargePayment(int itemID) 
{
    double price = getPrice(itemID);
    payment->charge(price);
}

void IVendingMachine::printReceipt(int itemID)
{
    auto& info = items.at(itemID);
    payment->printReceipt("Товар=" + info.label + ", цена=" + std::to_string(info.price));
}

void IVendingMachine::dispense(const std::string& itemLabel)
{
    std::cout << "Выдача: " << itemLabel << "\n";
}