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
    std::cout << "WiFi (����� " << channel
        << ", ������: " << signalStrength << " ���) ����������� � ������������ ����������.\n";
}

void WiFiCommunication::sendData(const std::string& data) 
{
    environment->interact();
    std::cout << "WiFi (����� " << channel << ") ���������� ������: " << data 
        << ". ����������� ��������� �������: " << environment->getCommunicationAttenuation() << "\n";
}

std::string WiFiCommunication::receiveCommand()  
{
    std::string cmd = "WiFi: ����� �������"; //����� ����� ����������� �������� ��������� �������
    std::cout << cmd << "\n";
    return cmd;
}

WiFiCommunication* WiFiCommunication::clone() const
{
	return new WiFiCommunication(*this);
}