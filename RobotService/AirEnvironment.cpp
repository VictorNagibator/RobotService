#include "AirEnvironment.h"
#include <iostream>

double AirEnvironment::getResistance() const 
{ 
	return 0.8; //������ ������������� (��������� ������������� ����� �������)
} 

double AirEnvironment::getNavigationAccuracyFactor() const 
{ 
	return 0.9; //������� ������, ������ ����� �� �����������
} 

double AirEnvironment::getCommunicationAttenuation() const 
{ 
	return 1.2; //������ ��������� ��-�� ����������� �������
} 

std::string AirEnvironment::getEnvironmentName() const 
{ 
	return "������"; 
}

void AirEnvironment::interact()
{
	std::cout << "�������������� � ��������..." << std::endl;
}