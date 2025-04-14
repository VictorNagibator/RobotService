#include "WiFiCommunication.h"
#include <iostream>

WiFiCommunication::WiFiCommunication(int signalStrength, int channel, IEnvironment* environment) 
    : ICommunication(signalStrength, environment)
{
    this->channel = channel;
}

void WiFiCommunication::establishConnection() 
{
    environment->interact();
    std::cout << "WiFi (Канал " << channel
        << ", Сигнал: " << signalStrength << " дБм) подключился к центральному управлению.\n";
}

void WiFiCommunication::sendData(const std::string& data) 
{
    environment->interact();
    std::cout << "WiFi (Канал " << channel << ") отправляет данные: " << data 
        << ". Коэффициент затухания сигнала: " << environment->getCommunicationAttenuation() << "\n";
}

std::string WiFiCommunication::receiveCommand()  
{
    std::string cmd = "WiFi: некая команда"; //Можно будет реализовать реальное получение команды
    std::cout << cmd << "\n";
    return cmd;
}

WiFiCommunication* WiFiCommunication::clone() const
{
	return new WiFiCommunication(*this);
}