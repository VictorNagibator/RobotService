#include "OpenDoorCommand.h"

std::string OpenDoorCommand::name() const
{
    return "�������� ������";
}

void OpenDoorCommand::execute() 
{
    vendingMachine->openDoor();
}