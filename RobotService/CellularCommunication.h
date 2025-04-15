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

    //�����, ������� ������������ � ������ ������
	ICellularChannel* channel;
public:
    CellularCommunication(int signalStrength, int latency, IEnvironment* environment, CellularChannelPool* pool);

    void establishConnection() override;
	void disconnect() override; //����� ���������� �� ����
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

    //����� ��� ���������� �������� ����������
    void updateLatency(int newLatency);

    CellularCommunication* clone() const override;
};