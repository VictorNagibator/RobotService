#include "WiFiCommunication.h"
#include <iostream>

WiFiCommunication::WiFiCommunication(int signalStrength, int channel) : ICommunication(signalStrength)
{
    this->channel = channel;
}

void WiFiCommunication::establishConnection() 
{
    std::cout << "WiFi (Канал " << channel
        << ", Сигнал: " << signalStrength << " дБм) подключился к центральному управлению.\n";
}

void WiFiCommunication::sendData(const std::string& data) 
{
    std::cout << "WiFi (Канал " << channel << ") отправляет данные: " << data << "\n";
}

std::string WiFiCommunication::receiveCommand()  
{
    std::string cmd = "WiFi: некая команда"; //Можно будет реализовать реальное получение команды
    std::cout << cmd << "\n";
    return cmd;
}