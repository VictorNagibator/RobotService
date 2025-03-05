#pragma once
#include "ICommunication.h"

//Реализация системы связи по WiFi
class WiFiCommunication : public ICommunication {
private:
    int signalStrength; //Сила сигнала в дБм
    int channel; //Номер канала WiFi
public:
    WiFiCommunication(int signalStrength, int channel);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //Метод для обновления силы сигнала
    void updateSignalStrength(int newStrength);
};

