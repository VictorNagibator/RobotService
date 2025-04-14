#pragma once
#include "CommunicationFactory.h"

class WiFiCommunicationFactory :
    public CommunicationFactory
{
private:
    int standartChannel;
public:
	//���������� ����������� � ����, ����� ��������� ���������������� ����� ��� �������� ������ WiFi
	//(��� ���������� ������ ����� ���������������� �� ����� ���)
	WiFiCommunicationFactory(int channel = 5) : standartChannel(channel) {}
	ICommunication* createCommunication(int signalStrength, IEnvironment* env) override;
};