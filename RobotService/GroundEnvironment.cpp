#include "GroundEnvironment.h"

//������� ��� ������������ �� 1 � �������� ���������

double GroundEnvironment::getResistance() const
{ 
	return 1.0; 
}

double GroundEnvironment::getNavigationAccuracyFactor() const
{ 
	return 1.0; 
}

double GroundEnvironment::getCommunicationAttenuation() const
{ 
	return 1.0;
}

std::string GroundEnvironment::getEnvironmentName() const
{ 
	return "�����"; 
}