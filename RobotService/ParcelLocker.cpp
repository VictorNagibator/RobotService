#include "ParcelLocker.h"

void ParcelLocker::openDoor() 
{
    std::cout << "[Автомат по выдаче посылок] Открыта ячейка\n";
}

void ParcelLocker::dispense(const std::string& itemLabel)
{
    std::cout << "[Автомат по выдаче посылок] Выдана посылка #" << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void ParcelLocker::closeDoor()
{
    std::cout << "[Автомат по выдаче посылок] Ячейка закрыта\n";
}