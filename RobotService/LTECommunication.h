#pragma once
#include "ICommunication.h"

class LTECommunication : public ICommunication
{
private:
    int latency; //�������� � ��
public:
    LTECommunication(int latency);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //����� ��� ���������� �������� ����������
    void updateLatency(int newLatency);
};