#pragma once
#include "ICommunication.h"

//Реализация системы связи по WiFi
class WiFiCommunication : public ICommunication {
private:
    int channel; //Номер канала WiFi
public:
    WiFiCommunication(int signalStrength, int channel, IEnvironment* environment);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    WiFiCommunication* clone() const override;
};