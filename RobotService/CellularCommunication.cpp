#include "CellularCommunication.h"
#include <iostream>

CellularCommunication::CellularCommunication(int signalStrength, int latency, IEnvironment* environment, int poolSize) 
    : ICommunication(signalStrength, environment)
{
    this->latency = latency;
	channelPool = new CellularChannelPool(poolSize); //������� ��� �������
}

CellularCommunication::~CellularCommunication()
{
	delete channelPool; //����������� ������, ���������� ��� ��� �������
}

void CellularCommunication::establishConnection() 
{
    environment->interact();
    std::cout << "��������� ����� (��������: " 
        << latency << " ��). ����������� � ������������ ����������.\n";
}

void CellularCommunication::sendData(const std::string& data)
{
    environment->interact();

    //�������� ����� �� ����
    CellularChannel* channel = channelPool->acquire();
    //�������� ��������� ����� �����
    channel->transmit(data);
    //���������� ����� ������� � ���
    channelPool->release(channel);
}

std::string CellularCommunication::receiveCommand()
{
    std::string cmd = "��������� �����: ����� �������";
    std::cout << cmd << "\n";
    return cmd;
}

void CellularCommunication::updateLatency(int newLatency) 
{
    latency = newLatency;
}

CellularCommunication* CellularCommunication::clone() const
{
	return new CellularCommunication(*this);
}