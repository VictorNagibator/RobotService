#include "CellularCommunication.h"
#include <iostream>

CellularCommunication::CellularCommunication(int signalStrength, int latency, IEnvironment* environment) 
    : ICommunication(signalStrength, environment)
{
    this->latency = latency;
}

void CellularCommunication::establishConnection() 
{
    environment->interact();
    std::cout << "Мобильная связь (Задержка: " 
        << latency << " мс). Подключение к центральному управлению.\n";
}

void CellularCommunication::sendData(const std::string& data)
{
    environment->interact();
    std::cout << "Мобильная связь отправляет данные: " << data 
        << ". Коэффициент затухания сигнала: " << environment->getCommunicationAttenuation() << "\n";
}

std::string CellularCommunication::receiveCommand()
{
    std::string cmd = "Мобильная связь: некая команда";
    std::cout << cmd << "\n";
    return cmd;
}

void CellularCommunication::updateLatency(int newLatency) 
{
    latency = newLatency;
}

CellularCommunication* CellularCommunication::clone() const
{
	return new CellularCommunication(*this);
}