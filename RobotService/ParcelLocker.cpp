#include "ParcelLocker.h"

void ParcelLocker::openDoor() 
{
    std::cout << "[������� �� ������ �������] ������� ������\n";
}

void ParcelLocker::dispense(const std::string& itemLabel)
{
    std::cout << "[������� �� ������ �������] ������ ������� #" << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void ParcelLocker::closeDoor()
{
    std::cout << "[������� �� ������ �������] ������ �������\n";
}