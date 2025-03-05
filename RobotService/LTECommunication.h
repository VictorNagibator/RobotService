#pragma once
#include "ICommunication.h"

class LTECommunication : public ICommunication
{
private:
    int latency; //Задержка в мс
public:
    LTECommunication(int latency);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //Метод для обновления задержки соединения
    void updateLatency(int newLatency);
};