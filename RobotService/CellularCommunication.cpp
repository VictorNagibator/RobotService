#include "CellularCommunication.h"
#include <iostream>

CellularCommunication::CellularCommunication(int signalStrength, int latency, 
    IEnvironment* environment, CellularChannelPool* pool) 
    : ICommunication(signalStrength, environment)
{
    this->latency = latency;
    channelPool = pool;
	channel = nullptr; //Изначально канал не подключен
}

void CellularCommunication::establishConnection() 
{
    environment->interact();

    //Получаем канал из пула
    channel = channelPool->acquire();

    std::cout << "Мобильная связь (Задержка: " 
        << latency << " мс). Подключение к центральному управлению.\n";
}

void CellularCommunication::disconnect()
{
	//Возвращаем канал обратно в пул
	channelPool->release(channel);
	std::cout << "Мобильная связь: отключение от центрального управления.\n";
}

void CellularCommunication::sendData(const std::string& data)
{
    environment->interact();
    //Передаем сообщение через канал
    channel->transmit(data);
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

int CellularCommunication::getSignalStrength() const 
{
	if (channel) return ICommunication::getSignalStrength(); //Если канал подключен, то возвращаем уровень сигнала
	return 0; //Если канал не подключен, то возвращаем 0
}