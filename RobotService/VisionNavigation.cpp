#include "VisionNavigation.h"
#include <iostream>

VisionNavigation::VisionNavigation(const std::string& resolution, int frameRate, double startX, double startY)
    : INavigation(startX, startY)
{
    this->resolution = resolution;
    this->frameRate = frameRate;
}

void VisionNavigation::navigate(const std::string& destination) 
{
    std::cout << "������������ ������: ���������� ������ " << resolution
        << " � " << frameRate
        << " FPS, ������� ������� �� \"" << destination << "\"."
        << "�������� ����������, ����������� �������� ���������: " << environment->getNavigationAccuracyFactor() << "\n";
}

void VisionNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY);
    std::cout << "������������ ������: �������� ������� (" << x << ", " << y << ").\n";
}

void VisionNavigation::adjustRoute() 
{
    std::cout << "������������ ������: ���������� �������� ����� ������ � �����: " 
        << environment->getEnvironmentName() << "...\n";
}