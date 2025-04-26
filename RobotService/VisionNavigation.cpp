#include "VisionNavigation.h"
#include <iostream>

VisionNavigation::VisionNavigation(IEnvironment* environment, 
    const std::string& resolution, int frameRate, double startX, double startY)
    : INavigation(environment, startX, startY)
{
    this->resolution = resolution;
    this->frameRate = frameRate;
}

void VisionNavigation::navigate(const std::string& destination) 
{
    environment->interact();
    std::cout << "������������ ������: ���������� ������ " << resolution
        << " � " << frameRate
        << " FPS, ������� ������� �� \"" << destination << "\"."
        << "�������� ����������, ����������� �������� ���������: " << environment->getNavigationAccuracyFactor() << "\n";
}

void VisionNavigation::updatePosition(double newX, double newY)
{
    environment->interact();
    INavigation::updatePosition(newX, newY);
    std::cout << "������������ ������: �������� ������� (" << x << ", " << y << ").\n";
}

void VisionNavigation::adjustRoute() 
{
    environment->interact();
    std::cout << "������������ ������: ���������� �������� ����� ������ � �����: " 
        << environment->getEnvironmentName() << "...\n";
}

VisionNavigation* VisionNavigation::clone() const
{
	return new VisionNavigation(*this);
}

bool VisionNavigation::selfTest() const
{
	if (frameRate <= 0) return false;
	return true;
}