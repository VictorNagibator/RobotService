#include "HSPAChannel.h"

void HSPAChannel::connect()
{
    std::cout << "[����� 3G] ��������������� ����������...\n";
}

void HSPAChannel::transmit(const std::string& message)
{
    std::cout << "[����� 3G] �������� ���������: " << message << "\n";
}

void HSPAChannel::disconnect()
{
    std::cout << "[����� 3G] ���������� �����������.\n";
}