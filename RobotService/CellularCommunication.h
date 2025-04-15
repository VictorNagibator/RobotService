#pragma once
#include "ICommunication.h"
#include "CellularChannelPool.h"

//����� ��� ��������� �����
class CellularCommunication : public ICommunication
{
private:
    int latency; //�������� � ��

    //��� ������� ��� �����
    CellularChannelPool* channelPool;
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment, int poolSize = 3);
	~CellularCommunication();

    void establishConnection() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //����� ��� ���������� �������� ����������
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};