#include "LTEChannel.h"

void LTEChannel::connect()
{
    std::cout << "[����� LTE] ��������������� ����������...\n";
}

void LTEChannel::transmit(const std::string& message)
{
    std::cout << "[����� LTE] �������� ���������: " << message << "\n";
}

void LTEChannel::disconnect() 
{
    std::cout << "[����� LTE] ���������� �����������.\n";
}