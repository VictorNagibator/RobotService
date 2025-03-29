#include "CombustionEngine.h"
#include <iostream>

void CombustionEngine::start() {
    currentRPM = RPMonInitial;
    std::cout << "��������� ����������� �������� " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << "; " 
        << "������������� �����: " << environment->getResistance()
        << ").\n";
}

void CombustionEngine::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    std::cout << "��������� ����������� �������� " << engineName << " ������������� ������.\n";
}