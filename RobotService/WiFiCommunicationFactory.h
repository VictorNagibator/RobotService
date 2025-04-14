#pragma once
#include "CommunicationFactory.h"

class WiFiCommunicationFactory :
    public CommunicationFactory
{
private:
    int standartChannel;
public:
	//Используем конструктор и поле, чтобы корректно инициализировать канал при создании модуля WiFi
	//(мне показалось плохой идеей инициализировать не пойми чем)
	WiFiCommunicationFactory(int channel = 5) : standartChannel(channel) {}
	ICommunication* createCommunication(int signalStrength, IEnvironment* env) override;
};