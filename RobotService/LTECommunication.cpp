#include "LTECommunication.h"
#include <iostream>

LTECommunication::LTECommunication(int signalStrength, int latency) : ICommunication(signalStrength)
{
    this->latency = latency;
}

void LTECommunication::establishConnection() 
{
    std::cout << "4G (Latency: " 
        << latency << " мс) подключился к центральному управлению.\n";
}

void LTECommunication::sendData(const std::string& data)
{
    std::cout << "4G отправляет данные: " << data 
        << ". Коэффициент затухания сигнала: " << environment->getCommunicationAttenuation() << "\n";
}

std::string LTECommunication::receiveCommand()
{
    std::string cmd = "4G: некая команда";
    std::cout << cmd << "\n";
    return cmd;
}

void LTECommunication::updateLatency(int newLatency) 
{
    latency = newLatency;
}