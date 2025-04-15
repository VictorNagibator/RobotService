#include "LTEChannel.h"

void LTEChannel::connect()
{
    std::cout << "[Канал 4G] Устанавливается соединение...\n";
}

void LTEChannel::transmit(const std::string& message)
{
    std::cout << "[Канал 4G] Передача сообщения: " << message << "\n";
}

void LTEChannel::disconnect() 
{
    std::cout << "[Канал 4G] Соединение разрывается.\n";
}