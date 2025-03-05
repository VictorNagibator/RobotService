#include "LTECommunication.h"
#include <iostream>

void LTECommunication::establishConnection() 
{
    std::cout << "4G (Latency: " 
        << latency << " ��) ����������� � ������������ ����������. \n";
}

void LTECommunication::sendData(const std::string& data)
{
    std::cout << "4G ���������� ������: " << data << "\n";
}

std::string LTECommunication::receiveCommand()
{
    std::string cmd = "4G: ����� �������";
    std::cout << cmd << "\n";
    return cmd;
}

void LTECommunication::updateLatency(int newLatency) 
{
    latency = newLatency;
}