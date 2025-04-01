#include "WaterEnvironment.h"
#include <iostream>

double WaterEnvironment::getResistance() const 
{ 
	return 1.5; //������� ���������������� ����
} 

double WaterEnvironment::getNavigationAccuracyFactor() const
{
	return 1.2; //������� � ���������� (������ GPS ����� ����������)
}

double WaterEnvironment::getCommunicationAttenuation() const
{
	return 1.5; //������� ��������� ������� � ����
}

std::string WaterEnvironment::getEnvironmentName() const
{
	return "����";
}

void WaterEnvironment::interact()
{
	std::cout << "�������������� � ����..." << std::endl;
}