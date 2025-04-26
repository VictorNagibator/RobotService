#include "DispenseItemCommand.h"
#include <string>

std::string DispenseItemCommand::name() const
{ 
    return "������ ������ (" + std::to_string(itemID) + ")";
}

void DispenseItemCommand::execute()
{
    auto label = std::to_string(itemID);
    vendingMachine->dispense(label);
}