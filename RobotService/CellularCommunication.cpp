#include "CellularCommunication.h"
#include <iostream>

CellularCommunication::CellularCommunication(int signalStrength, int latency, IEnvironment* environment, int poolSize) 
    : ICommunication(signalStrength, environment)
{
    this->latency = latency;
	channelPool = new CellularChannelPool(poolSize); //Создаем пул каналов
}

CellularCommunication::~CellularCommunication()
{
	delete channelPool; //Освобождаем память, выделенную под пул каналов
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

    //Получаем канал из пула
    CellularChannel* channel = channelPool->acquire();
    //Передаем сообщение через канал
    channel->transmit(data);
    //Возвращаем канал обратно в пул
    channelPool->release(channel);
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