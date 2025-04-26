#include "TicketKiosk.h"

void TicketKiosk::openDoor()
{
    std::cout << "[������� �� ������� �������] ������� �����\n";
}

void TicketKiosk::dispense(const std::string& itemLabel)
{
    std::cout << "[������� �� ������� �������] �����: " << itemLabel << "\n";
    IVendingMachine::dispense(itemLabel);
}

void TicketKiosk::closeDoor()
{
    std::cout << "[������� �� ������� �������] ����� �����\n";
}