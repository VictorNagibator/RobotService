#pragma once
#include "ICommunication.h"

//����� ��� ��������� �����
class CellularCommunication : public ICommunication
{
private:
    int latency; //�������� � ��
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment);

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //����� ��� ���������� �������� ����������
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};