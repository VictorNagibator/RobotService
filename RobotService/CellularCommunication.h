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

    //Канал, который используется в данный момент
	ICellularChannel* channel;
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment, CellularChannelPool* pool);

    void establishConnection() override;
	void disconnect() override; //Метод отключения от сети
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //Метод для обновления задержки соединения
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};