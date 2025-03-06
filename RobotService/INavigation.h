#pragma once
#include <string>

//Абстрактный класс навигационной системы
class INavigation {
protected:
    double x, y; //Координаты робота
public:
    INavigation(double startX = 0, double startY = 0);

    //Навигация по маршруту к заданной точке
    virtual void navigate(const std::string& destination) = 0;
    //Обновление координат робота
    virtual void updatePosition(double newX, double newY);
    //Коррекция маршрута при возникновении препятствий
    virtual void adjustRoute() = 0;
};