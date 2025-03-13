#pragma once
#include <iostream>
#include <string>

//Сторонний класс навигации с собственными методами
class YandexNavigationSystem {
public:
    void navigateOnRoute(const std::string& destination);
    void updateCoords(double newX, double newY);
    void reAdjust();
};