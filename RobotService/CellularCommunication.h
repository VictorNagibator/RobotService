#pragma once
#include "ICommunication.h"

//Класс для мобильной связи
class CellularCommunication : public ICommunication
{
private:
    int latency; //Задержка в мс
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //Метод для обновления задержки соединения
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};