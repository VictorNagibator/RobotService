#include "HybridEngine.h"
#include <iostream>

void HybridEngine::start() {
    currentRPM = RPMonInitial;
    std::cout << "��������� ��������� " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << "; " 
        << "������������� �����: " << environment->getResistance()
        << ").\n";
}

void HybridEngine::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    std::cout << "��������� ��������� " << engineName << " ������������� ������.\n";
}