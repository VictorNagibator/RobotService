#include "ElectricMotor.h"
#include <iostream>

void ElectricMotor::start() {
    currentRPM = RPMonInitial; //���������������� ��������� ��������� ������� ��������
    std::cout << "������������ " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << ")\n";
}

void ElectricMotor::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    std::cout << "������������ " << engineName << " ������������� ������.\n";
}