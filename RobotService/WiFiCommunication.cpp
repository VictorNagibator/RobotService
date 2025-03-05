#include "WiFiCommunication.h"
#include <iostream>

WiFiCommunication::WiFiCommunication(int signalStrength, int channel)
{
    this->signalStrength = signalStrength;
    this->channel = channel;
}

void WiFiCommunication::establishConnection() 
{
    std::cout << "WiFi (����� " << channel
        << ", ������: " << signalStrength << " ���) ����������� � ������������ ����������.\n";
}

void WiFiCommunication::sendData(const std::string& data) 
{
    std::cout << "WiFi (����� " << channel << ") ���������� ������: " << data << "\n";
}

std::string WiFiCommunication::receiveCommand()  
{
    std::string cmd = "WiFi: ����� �������"; //����� ����� ����������� �������� ��������� �������
    std::cout << cmd << "\n";
    return cmd;
}

void WiFiCommunication::updateSignalStrength(int newStrength) {
    signalStrength = newStrength;
}