#include "ElectricMotor.h"
#include <iostream>

void ElectricMotor::start() {
    currentRPM = RPMonInitial; //���������������� ��������� ��������� ������� ��������
    environment->interact();
    std::cout << "������������ " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << "; " 
        << "������������� �����: " << environment->getResistance() 
        << ").\n";
}

void ElectricMotor::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    environment->interact();
    std::cout << "������������ " << engineName << " ������������� ������.\n";
}