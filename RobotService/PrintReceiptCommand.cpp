#include "PrintReceiptCommand.h"

std::string PrintReceiptCommand::name() const
{
    return "Печать чека"; 
}

void PrintReceiptCommand::execute()
{
    vendingMachine->printReceipt(itemID);
}