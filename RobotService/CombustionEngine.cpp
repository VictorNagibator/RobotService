#include "CombustionEngine.h"
#include <iostream>

void CombustionEngine::start() {
    currentRPM = RPMonInitial;
    environment->interact();
    std::cout << "��������� ����������� �������� " << engineName
        << " ���������. (�������: " << currentRPM
        << " / " << maxRPM << "; " 
        << "������������� �����: " << environment->getResistance()
        << ").\n";
}

void CombustionEngine::stop() {
    currentRPM = 0; //������� ���������� ����� ����, ��� ������ ���������
    environment->interact();
    std::cout << "��������� ����������� �������� " << engineName << " ������������� ������.\n";
}

CombustionEngine* CombustionEngine::clone() const
{
	return new CombustionEngine(*this);
}