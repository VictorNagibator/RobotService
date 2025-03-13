#pragma once
#include <iostream>
#include <string>

//��������� ����� ��������� � ������������ ��������
class YandexNavigationSystem {
public:
    void navigateOnRoute(const std::string& destination);
    void updateCoords(double newX, double newY);
    void reAdjust();
};