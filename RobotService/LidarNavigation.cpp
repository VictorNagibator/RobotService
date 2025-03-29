#include "LidarNavigation.h"
#include <iostream>

LidarNavigation::LidarNavigation(int detectionRange, double laserFrequency, double startX, double startY)
    : INavigation(startX, startY)
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
    updatePosition(newX, newY);
    std::cout << "�����: ��������� ������� (" << x << ", " << y << ").\n";
}

void LidarNavigation::adjustRoute()
{
    std::cout << "�����: ������� ���������� � ������ ����������� � �����: " << environment->getEnvironmentName() << "...\n";
}