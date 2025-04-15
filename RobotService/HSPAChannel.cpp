#include "HSPAChannel.h"

void HSPAChannel::connect()
{
    std::cout << "[Канал 3G] Устанавливается соединение...\n";
}

void HSPAChannel::transmit(const std::string& message)
{
    std::cout << "[Канал 3G] Передача сообщения: " << message << "\n";
}

void HSPAChannel::disconnect()
{
    std::cout << "[Канал 3G] Соединение разрывается.\n";
}