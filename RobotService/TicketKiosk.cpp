#include "TicketKiosk.h"

void TicketKiosk::openDoor()
{
    std::cout << "[Автомат по продаже билетов] Принтер готов\n";
}

void TicketKiosk::dispense(const std::string& itemLabel)
{
    std::cout << "[Автомат по продаже билетов] Билет: " << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void TicketKiosk::closeDoor()
{
    std::cout << "[Автомат по продаже билетов] Билет выдан\n";
}