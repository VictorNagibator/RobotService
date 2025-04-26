#include "CloseDoorCommand.h"

std::string CloseDoorCommand::name() const
{ 
    return "Закрытие дверцы"; 
}
void CloseDoorCommand::execute()
{
    vendingMachine->closeDoor();
}