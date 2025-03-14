#pragma once
#include "ICommunication.h"

//���������� ������� ����� �� WiFi
class WiFiCommunication : public ICommunication {
private:
    int channel; //����� ������ WiFi
public:
    WiFiCommunication(int signalStrength, int channel);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;
};