#include "LTEChannel.h"

void LTEChannel::connect()
{
    std::cout << "[����� 4G] ��������������� ����������...\n";
}

void LTEChannel::transmit(const std::string& message)
{
    std::cout << "[����� 4G] �������� ���������: " << message << "\n";
}

void LTEChannel::disconnect() 
{
    std::cout << "[����� 4G] ���������� �����������.\n";
}