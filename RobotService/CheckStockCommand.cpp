#include "CheckStockCommand.h"
#include <string>

std::string CheckStockCommand::name() const 
{ 
    return "�������� ������� (" + std::to_string(itemID) + ")"; 
}
void CheckStockCommand::execute()
{
    std::cout << "�������� ������� ������ " << itemID << "\n";
    if (!vendingMachine->hasItem(itemID))
        throw std::runtime_error("����� " + std::to_string(itemID) + " �����������");
}