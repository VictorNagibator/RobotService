#include "PrintReceiptCommand.h"

std::string PrintReceiptCommand::name() const
{
    return "������ ����"; 
}

void PrintReceiptCommand::execute()
{
    vendingMachine->printReceipt(itemID);
}