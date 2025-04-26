#include "OpenDoorCommand.h"

std::string OpenDoorCommand::name() const
{
    return "Открытие дверки";
}

void OpenDoorCommand::execute() 
{
    vendingMachine->openDoor();
}