#include "CloseDoorCommand.h"

std::string CloseDoorCommand::name() const
{ 
    return "�������� ������"; 
}
void CloseDoorCommand::execute()
{
    vendingMachine->closeDoor();
}