#include "CellularCommunication.h"
#include <iostream>

CellularCommunication::CellularCommunication(int signalStrength, int latency, 
    IEnvironment* environment, CellularChannelPool* pool) 
    : ICommunication(signalStrength, environment)
{
    this->latency = latency;
    channelPool = pool;
	channel = nullptr; //���������� ����� �� ���������
}

void CellularCommunication::establishConnection() 
{
    environment->interact();

    //�������� ����� �� ����
    channel = channelPool->acquire();

    std::cout << "��������� ����� (��������: " 
        << latency << " ��). ����������� � ������������ ����������.\n";
}

void CellularCommunication::disconnect()
{
	//���������� ����� ������� � ���
	channelPool->release(channel);
	std::cout << "��������� �����: ���������� �� ������������ ����������.\n";
}

void CellularCommunication::sendData(const std::string& data)
{
    environment->interact();
    //�������� ��������� ����� �����
    channel->transmit(data);
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

int CellularCommunication::getSignalStrength() const 
{
	if (channel) return ICommunication::getSignalStrength(); //���� ����� ���������, �� ���������� ������� �������
	return 0; //���� ����� �� ���������, �� ���������� 0
}