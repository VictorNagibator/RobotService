#include "CheckStockCommand.h"
#include <string>

std::string CheckStockCommand::name() const 
{ 
    return "Проверка наличия (" + std::to_string(itemID) + ")"; 
}
void CheckStockCommand::execute()
{
    std::cout << "Проверка наличия товара " << itemID << "\n";
    if (!vendingMachine->hasItem(itemID))
        throw std::runtime_error("Товар " + std::to_string(itemID) + " отсутствует");
}