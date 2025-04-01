#include "LidarNavigation.h"
#include <iostream>

LidarNavigation::LidarNavigation(IEnvironment* environment, int detectionRange, 
    double laserFrequency, double startX, double startY)
    : INavigation(environment, startX, startY)
{
    this->detectionRange = detectionRange;
    this->laserFrequency = laserFrequency;
}

void LidarNavigation::navigate(const std::string& destination) 
{
    std::cout << "�����: �������� ��������� � ������� "
        << detectionRange << " �. � �������� ������ " << laserFrequency
        << " �� ��� ��������� �� \"" << destination << "\"."
        << "�������� ����������, ����������� �������� ���������: " << environment->getNavigationAccuracyFactor() << "\n";
}

void LidarNavigation::updatePosition(double newX, double newY)
{
    environment->interact();
    updatePosition(newX, newY);
    std::cout << "�����: ��������� ������� (" << x << ", " << y << ").\n";
}

void LidarNavigation::adjustRoute()
{
    environment->interact();
    std::cout << "�����: ������� ���������� � ������ ����������� � �����: " << environment->getEnvironmentName() << "...\n";
}