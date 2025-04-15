#pragma once
#include "ICommunication.h"
#include "CellularChannelPool.h"

//Класс для мобильной связи
class CellularCommunication : public ICommunication
{
private:
    int latency; //Задержка в мс

    //Пул каналов для связи
    CellularChannelPool* channelPool;
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment, int poolSize = 3);
	~CellularCommunication();

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //Метод для обновления задержки соединения
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};