#pragma once
#include "ICommunication.h"

class LTECommunication : public ICommunication
{
private:
    int latency; //�������� � ��
public:
    LTECommunication(int signalStrength, int latency, IEnvironment* environment);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //����� ��� ���������� �������� ����������
    void updateLatency(int newLatency);

    LTECommunication* clone() const override;
};