#include "HybridEngine.h"
#include <iostream>

void HybridEngine::start() {
    currentRPM = RPMonInitial;
    environment->interact();
    std::cout << "��������� ��������� " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << "; " 
        << "������������� �����: " << environment->getResistance()
        << ").\n";
}

void HybridEngine::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    environment->interact();
    std::cout << "��������� ��������� " << engineName << " ������������� ������.\n";
}