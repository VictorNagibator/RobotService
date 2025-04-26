#include "CoffeeVendingMachine.h"

void CoffeeVendingMachine::openDoor()
{
    std::cout << "[Кофейный Автомат] Готовлю чашку...\n";
}

void CoffeeVendingMachine::dispense(const std::string& itemLabel)
{
    std::cout << "[Кофейный Автомат] Наливаю " << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void CoffeeVendingMachine::closeDoor() 
{
    std::cout << "[Кофейный Автомат] Чашка готова\n";
}