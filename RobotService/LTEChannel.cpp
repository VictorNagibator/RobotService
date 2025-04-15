#include "LTEChannel.h"

void LTEChannel::connect()
{
    std::cout << "[Канал LTE] Устанавливается соединение...\n";
}

void LTEChannel::transmit(const std::string& message)
{
    std::cout << "[Канал LTE] Передача сообщения: " << message << "\n";
}

void LTEChannel::disconnect() 
{
    std::cout << "[Канал LTE] Соединение разрывается.\n";
}