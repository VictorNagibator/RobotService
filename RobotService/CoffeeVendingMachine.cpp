#include "CoffeeVendingMachine.h"

void CoffeeVendingMachine::openDoor()
{
    std::cout << "[�������� �������] ������� �����...\n";
}

void CoffeeVendingMachine::dispense(const std::string& itemLabel)
{
    std::cout << "[�������� �������] ������� " << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void CoffeeVendingMachine::closeDoor() 
{
    std::cout << "[�������� �������] ����� ������\n";
}