#include "YandexNavigationSystem.h"

void YandexNavigationSystem::navigateOnRoute(const std::string& destination)
{
    std::cout << "������� ��������� ������: � ������� ����� �������� ������� ���������� ������� �� " << destination << ".\n";
}

void YandexNavigationSystem::updateCoords(double newX, double newY)
{
    std::cout << "������� ��������� ������: �������� ���������� (" << newX << ", " << newY << ").\n";
}

void YandexNavigationSystem::reAdjust()
{
    std::cout << "������� ��������� ������: �������� ������� ��-�� �����������...\n";
}