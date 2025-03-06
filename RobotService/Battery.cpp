#include "Battery.h"

Battery::Battery(int capacity) 
{
    this->capacity = capacity;
}

double Battery::getCharge() const 
{
    return (currentCharge / capacity) * 100.0; //��������� � ��������
}

void Battery::recharge()
{
    currentCharge = capacity;
    std::cout << "������� ���������� �� 100%.\n";
}

void Battery::consume(double usage) {
    if (currentCharge < usage) throw std::exception("������������ �������!");

	currentCharge -= usage;
    std::cout << "������� �����������. ������� �����: " << getCharge() << "%\n";
}